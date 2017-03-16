/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WorldNode.h
 * Author: studentlocal
 *
 * Created on March 14, 2017, 11:39 AM
 */

#ifndef WORLDNODE_H
#define WORLDNODE_H

#include <SFML/Graphics.hpp>
#include "WindowManager.h"

class WorldNode {
public:
    WorldNode();
    WorldNode(WindowManager* _window, int _x, int _y);
    ~WorldNode();
    void load();
    void unload();
    void update();
    void draw();
    unsigned int x, y;
private:
    WindowManager* window;
    bool loaded;
    const float width = 1920;
    const float height = 1080;
    
    //temp
    sf::RectangleShape bg;
};

#endif /* WORLDNODE_H */

