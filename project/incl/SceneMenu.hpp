/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SceneMenu.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:46:51 by banthony          #+#    #+#             */
/*   Updated: 2018/04/30 16:46:51 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_SCENEMENU_HPP
#define PROJECT_SCENEMENU_HPP

#include "AScene.hpp"

class SceneMenu : public AScene {

public:
    SceneMenu(AGraphics *aGraphics);
    ~SceneMenu(); // Canonical

private:
    SceneMenu(); // Canonical
    SceneMenu(SceneMenu const &copy); // Canonical

    SceneMenu &operator=(SceneMenu const &copy); // Canonical

public:
    void eventHandler(std::vector<eEvent> eventList) override;

    void drawScene() override;

};


#endif //PROJECT_SCENEMENU_HPP