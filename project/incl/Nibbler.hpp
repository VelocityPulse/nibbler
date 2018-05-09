/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nibbler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:51:29 by banthony          #+#    #+#             */
/*   Updated: 2018/04/26 17:51:29 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HPP
#define NIBBLER_HPP

#include <iostream>
#include <string>
#include <map>
#include <dlfcn.h>
#include "AGraphics.hpp"
#include "AScene.hpp"
#include "SceneMenu.hpp"
#include "SceneSkin.hpp"
#include "SceneGame.hpp"
#include "SceneGameEnd.hpp"

// Calcul x % de val
#define PERCENTAGE(x, val) ((x * val) / 100)

enum eScene {
	STATE_VOID,
	MENU,
	GAME,
	SKIN,
	GAME_END,
	NB_STATE
};

class Nibbler {

public:
	typedef std::map<eScene, AScene *> MapScene;
	static char *pathLibSDL;
	static char *pathLibOpenGL;
	static char *pathLibSFML;

	static void *_dlHandle;
	static AGraphics *_aGraphics;
	// TODO add a current lib, add the name of the lib on the screen

	static int getWindowWidth();
	static void setWindowWidth(int w);
	static int getWindowHeight();
	static void setWindowHeight(int h);
	static eScene getCurrentScene();
	static void setCurrentScene(eScene _currentScene);

	static Nibbler *getInstance();
	static bool loadLibrary(std::string const string);
	static void closeDlHandle();

	void run();

private:
	static AGraphics *(*_deleteAGraphics)(AGraphics *);
	static Nibbler *_singleton;
	static eScene _currentScene;
	static int WINDOW_WIDTH;
	static int WINDOW_HEIGHT;
	MapScene _callScene;

	void initRun();

	Nibbler(); // Canonical
	Nibbler(Nibbler const &copy); // Canonical
	~Nibbler(); // Canonical
	Nibbler &operator=(Nibbler const &copy); // Canonical
};

/*

+ enum eStateGame { MENU, GAME, SKIN, GAME_END, NB_STATE } // Définit les différent états du jeux
+ enum eTexture { MENU_BCKG, GAME_BCKG, SCORE_BCKG, ITEM1, ITEM2, NB_TEXTURE } // Définit les différentes textures du jeux
+ typedef void (*t_displayer)(void *data)
+ typedef void (*t_event)(void *data)

+ AGraphics                *aGraphics;
+ Nibbler                     *singleton;
+ std::vector<char>     _map
+ int                             _skin[SIZE_INIT];
+ t_displayer               _displayer[NB_STATE]             // Tableau de fonction d'affichage, une pour chaque état du jeu
+ t_event                     _eventManager[NB_STATE]    // Tableau de fonction d'event, une pour chaque état du jeu

*/


#endif //PROJECT_NIBBLER_HPP