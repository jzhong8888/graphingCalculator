#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H

#include <vector>
#include <string>
#include <map>
#include <stack>
#include <cmath>
#include <cassert>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>


#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/token.h"
#include "../token/operator.h"
#include "../token/integer.h"
#include "../token/function.h"
#include "../token/leftparen.h"
#include "../token/rightparen.h"
#include "../shunting_yard/shunting_yard.h"
#include "../rpn/rpn.h"
#include "../vector/vector_class.h"
#include "../constants.h"

using namespace std;




struct GraphInfo {

    GraphInfo(){
        // _equation = "sin(x)";
        // _domain = sf::Vector2f(MIN_DOMAIN, MAX_DOMAIN);
        // _num_of_points = NUM_OF_POINTS;
        // _screen_size = sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT);
        // int graph_unit = _screen_size.x / (_num_of_points - 1);
        // int screen_origin_x = 0 + (0 - _domain.x)*graph_unit;
        // int screen_origin_y = _screen_size.y / 2;
        // sf::Vector2f screen_origin(screen_origin_x, screen_origin_y);
        // _screen_origin = screen_origin;

        _equation = "0";
        _domain = sf::Vector2f(MIN_DOMAIN,MAX_DOMAIN);
        _num_of_points = NUM_OF_POINTS;
        _screen_size = sf::Vector2f(WORK_PANEL, SCREEN_HEIGHT);
        // double graph_unit = _screen_size.x / (_num_of_points - 1);
        // double screen_origin_x = 0 + (0 - _domain.x)*graph_unit;
        // double screen_origin_y = _screen_size.y / 2;
        // sf::Vector2f screen_origin(screen_origin_x, screen_origin_y);
        // _screen_origin = screen_origin;
    }

    // GraphInfo(string equation, sf::Vector2f domain, int num_of_points, sf::Vector2f screen_size){
    //     _equation = equation;
    //     _domain = domain;
    //     _num_of_points = num_of_points;
    //     _screen_size = screen_size;
    //     double graph_unit = screen_size.x / (num_of_points - 1);
    //     double screen_origin_x = 0 + (0 - domain.x)*graph_unit;
    //     double screen_origin_y = screen_size.y / 2;
    //     sf::Vector2f screen_origin(screen_origin_x, screen_origin_y);
    //     _screen_origin = screen_origin;
    // }


    string _equation;
    sf::Vector2f _domain;
    int _num_of_points;
    sf::Vector2f _screen_size;
    // sf::Vector2f _screen_origin;


};

#endif