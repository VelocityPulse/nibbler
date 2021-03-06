/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:51:20 by banthony          #+#    #+#             */
/*   Updated: 2018/05/07 16:51:20 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

#include "../incl/AGraphics.hpp"

// Calcul de la position en pixel dans la texture pour le caracatere c
#define FONT_START_X(c) (CHAR_SIZE_X * ((c - '!') % NB_CHAR))
#define FONT_START_Y(c) (CHAR_SIZE_Y * ((c - '!') / NB_CHAR))

class Graphics : public AGraphics {

public:
	Graphics(); // Canonical
	Graphics(Graphics const &copy); // Canonical
	virtual ~Graphics(); // Canonical

	Graphics &operator=(Graphics const &copy); // Canonical

	void init(int windowWidth, int windowHeight, std::string windowName);

	int loopUpdate();
	void display();
	void clear();
	void putCharScreen(char const c, t_coordd pos, t_coordd sizeFont);
	void putStrScreen(std::string str, int posX, int posY, float size);
	void loadFontTexture(std::string path);
	void loadTexture(std::string path, int key);
	void cleanUp();

	std::vector<eEvent> &getEvent();

	unsigned char getChar();

	void putTexture(int key, int posX, int posY, int sizeX, int sizeY);


private:
	sf::RenderWindow *_window;
	std::map<int, sf::Texture> _textureList;
	std::vector<sf::Sprite> _spriteList;
	sf::Texture _fontTexture;
	bool _windowTerminated;
	std::map<sf::Keyboard::Key, eEvent> _eventLibMap;
};

extern "C" {
Graphics *createGraphics();
void deleteGraphics(Graphics *graphics);
}


#endif //NIBBLER_GRAPHICS_HPP