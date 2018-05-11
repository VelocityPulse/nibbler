/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SceneGame.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:46:35 by banthony          #+#    #+#             */
/*   Updated: 2018/04/30 16:46:35 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENEGAME_HPP
#define SCENEGAME_HPP

#include "AScene.hpp"
#include "Nibbler.hpp"

typedef struct {
	t_coordd headPos;
	t_coordd tailPos;
	t_coordd vec;
	int size;
	eTexture headSkin;
	eTexture bodySkin;
} t_snake;

typedef struct {
	t_coordd pos;
	int energy;    // TODO définir l'utilité
	eTexture skin;
} t_food;


class SceneGame : public AScene {

public:
	static eTexture _selectedHeadSkin;
	static eTexture _selectedBodySkin;
	SceneGame(AGraphics **aGraphics);
	~SceneGame(); // Canonical

	void eventHandler(std::vector<eEvent> eventList);

	void drawScene();

private:
	SceneGame(); // Canonical
	SceneGame(SceneGame const &copy); // Canonical
	SceneGame &operator=(SceneGame const &copy); // Canonical

	void moveSnake();

	static const int _N_SECTX = 16;    //TODO Voir si on calcul ces valeurs en fonctions de la taille de la fenetre
	static const int _N_SECTY = 16;
	t_snake _snake;
	t_food _food;            //TODO: Definir le nb de food max sur scene, dans ce cas: _food[MAX_FOOD]
};


#endif //PROJECT_SCENEGAME_HPP