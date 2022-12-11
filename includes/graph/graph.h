#ifndef GRAPH_H
#define GRAPH_H

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
#include "../plot/plot.h"
#include "../graph_info/graph_info.h"

using namespace std;

class Graph {
public:

    Graph(){
        _info = new GraphInfo();
        _plotter.set_info(_info);

    
        Vector<sf::Vector2f> points = _plotter();
        _screen_points = vector<sf::CircleShape>(_info->_num_of_points, sf::CircleShape(3));
        for (int i = 0; i < _info->_num_of_points; i++){
            _screen_points[i].setPosition(points[i]);
        }
    }

    Graph(GraphInfo* graph_ptr){
        _info = graph_ptr;
        _plotter.set_info(graph_ptr);
        Vector<sf::Vector2f> points = _plotter();
        _screen_points = vector<sf::CircleShape>(_info->_num_of_points, sf::CircleShape(3));
        // cout << "postfix: ";
        for (int i = 0; i < _info->_num_of_points; i++){
            _screen_points[i].setPosition(points[i]);
        }
    }

    void set_info(GraphInfo* graph_ptr){
        _info = graph_ptr;
        _plotter.set_info(graph_ptr);
        Vector<sf::Vector2f> points = _plotter();
    //     Queue<Token*> postfix = _plotter.get_postfix();
    //     cout << "postfix: ";
    //        for (Queue<Token *>::Iterator it = postfix.begin(); it != postfix.end(); it++){
    // cout <<setw(3)<< *it;
    // }
    // cout << endl; 
        _screen_points = vector<sf::CircleShape>(_info->_num_of_points, sf::CircleShape(3));
        for (int i = 0; i < _info->_num_of_points; i++){
            _screen_points[i].setPosition(points[i]);
        }
    }

    void update(GraphInfo* graph_ptr){
        _info = graph_ptr;
        _plotter.set_info(graph_ptr);
        Vector<sf::Vector2f> points = _plotter(graph_ptr);
    //     Queue<Token*> postfix = _plotter.get_postfix();
    //        for (Queue<Token *>::Iterator it = postfix.begin(); it != postfix.end(); it++){
    // cout <<setw(3)<< *it;
    // }
    // cout << endl; 
        _screen_points = vector<sf::CircleShape>(graph_ptr->_num_of_points, sf::CircleShape(3));
        for (int i = 0; i < graph_ptr->_num_of_points; i++){
            _screen_points[i].setPosition(points[i]);
        }
    }

    void draw(sf::RenderWindow& window, GraphInfo* &graph_ptr){
        
        update(graph_ptr);

        for (int i = 0; i < _info->_num_of_points; i++){
            window.draw(_screen_points[i]);
        }

        double delta = (graph_ptr->_domain.y - graph_ptr->_domain.x) / (graph_ptr->_num_of_points - 1) - 0.0000000000001;
        double graph_unit = graph_ptr->_screen_size.x / (graph_ptr->_num_of_points - 1);
        double screen_origin_x = (0 + (0 - graph_ptr->_domain.x))* (graph_unit/delta);
        double screen_origin_y = graph_ptr->_screen_size.y / 2;
        sf::Vector2f screen_origin(screen_origin_x, screen_origin_y);
        sf::Vertex xaxis[2];
        sf::Vertex yaxis[2];
        
        xaxis[0].position = sf::Vector2f(0, graph_ptr->_screen_size.y /2);
        xaxis[1].position = sf::Vector2f(graph_ptr->_screen_size.x, graph_ptr->_screen_size.y /2);

        
        yaxis[0].position = sf::Vector2f(screen_origin.x, 0);
        yaxis[1].position = sf::Vector2f(screen_origin.x, graph_ptr->_screen_size.y);

        window.draw(xaxis, 2, sf::Lines);
        window.draw(yaxis, 2, sf::Lines);



        /*
        sf::VertexArray points{sf::Points, _info->_num_of_points};
        for (int i = 0; i < _info->_num_of_points; i++){
            points[i].position = screen_points[i];
        }
        */
        //window.clear();
        //window.draw(points);
    }

    vector<sf::CircleShape> get_screen_points(){
        return _screen_points;
    }

private:
    GraphInfo* _info;
    Plot _plotter;
    //Vector<sf::Vector2f> screen_points;
    vector<sf::CircleShape> _screen_points;
    
    sf::Font font;
};

#endif