#ifndef PLOT_H
#define PLOT_H

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
#include "../graph_info/graph_info.h"
#include "../tokenizer/tokenizer.h"


using namespace std;

class Plot
{
public:


Plot(){
    set_info(_graph_ptr);
}


Plot(GraphInfo* graph_ptr){
    set_info(graph_ptr);
}

void set_info(GraphInfo* graph_ptr){
    _graph_ptr = graph_ptr;
    Tokenizer tokenizer(graph_ptr->_equation);
    //cout<< graph_ptr->_equation << endl;
    Queue<Token*> infix = tokenizer.infix();
    //        for (Queue<Token *>::Iterator it = infix.begin(); it != infix.end(); it++){
    // cout <<setw(3)<< *it;
    // }
    // cout << endl;
    ShuntingYard sy(infix);
    _postfix = sy.postfix();
}


// Vector<sf::Vector2f> get_coords(GraphInfo* graph_ptr){
    
//     double delta = (graph_ptr->_domain.y - graph_ptr->_domain.x) / graph_ptr->_num_of_points - 0.0000000000001;
//     Vector<sf::Vector2f> graph_points;
//     for (double i = graph_ptr->_domain.x; i <= graph_ptr->_domain.y; i+=delta){
//         RPN rpn(_postfix);
//         double y = rpn(i);
//         sf::Vector2f point(i, y);
//         graph_points += point;
//     }
//     return graph_to_screen(graph_points);
// }

// Vector<sf::Vector2f> get_coords(){
//     //cout << "max domain: " << _graph_ptr->_max_domain << endl;
//     double delta = (_graph_ptr->_domain.y - _graph_ptr->_domain.x) / (_graph_ptr->_num_of_points - 1) - 0.0000000000001;
//     //Vector<sf::Vector2f> graph_points;
//     int count = 0;
//     for (double i = _graph_ptr->_domain.x; i <= _graph_ptr->_domain.y; i+=delta){
//         RPN rpn(_postfix);
//         double y = rpn(i);
//         sf::Vector2f point(i, y);
//         _graph_points += point;
//         //cout << "count: " << count++ << endl;
//     }
//     //return _graph_points;
//     return this->graph_to_screen();
// }

Vector<sf::Vector2f> operator()(){
    double delta = (_graph_ptr->_domain.y - _graph_ptr->_domain.x) / (_graph_ptr->_num_of_points - 1) - 0.0000000000001;
    //int count = 0;
    for (double i = _graph_ptr->_domain.x; i <= _graph_ptr->_domain.y; i+=delta){
        RPN rpn(_postfix);
        double y = rpn(i);
        sf::Vector2f point(i, y);
        _graph_points += point;

        //count++;
        
    }
    //cout << "count: " << count << endl;
    return this->graph_to_screen(delta);
}

Vector<sf::Vector2f> operator()(GraphInfo* graph_ptr){
    
    double delta = (graph_ptr->_domain.y - graph_ptr->_domain.x) / (graph_ptr->_num_of_points - 1) - 0.0000000000001;
    Vector<sf::Vector2f> graph_points;
    for (double i = graph_ptr->_domain.x; i <= graph_ptr->_domain.y; i+=delta){
        RPN rpn(_postfix);
        double y = rpn(i);
        sf::Vector2f point(i, y);
        graph_points += point;
    }
    //return graph_to_screen(graph_points, delta);
    double graph_unit = graph_ptr->_screen_size.x / (graph_ptr->_num_of_points - 1);
    double screen_origin_x = (0 + (0 - graph_ptr->_domain.x))* (graph_unit/delta);
    double screen_origin_y = graph_ptr->_screen_size.y / 2;
    sf::Vector2f screen_origin(screen_origin_x, screen_origin_y);
    //_screen_origin = screen_origin;

    Vector<sf::Vector2f> screen_points(graph_points.size());
    for (double i = 0; i < screen_points.size(); i++){
        screen_points[i].x = screen_origin.x + graph_points[i].x * (graph_unit/delta);
        screen_points[i].y = screen_origin.y - graph_points[i].y * (graph_unit/delta);
    }
    return screen_points;
}


Vector<sf::Vector2f> graph_to_screen(double delta){
    double graph_unit = _graph_ptr->_screen_size.x / (_graph_ptr->_num_of_points - 1);
    double screen_origin_x = (0 + (0 - _graph_ptr->_domain.x))* (graph_unit/delta);
    double screen_origin_y = _graph_ptr->_screen_size.y / 2;
    sf::Vector2f screen_origin(screen_origin_x, screen_origin_y);
    //_screen_origin = screen_origin;
    //sf::Vector2f screen_origin(_graph_ptr->_screen_height / 2, _graph_ptr->_screen_width / 2);
    //double x_graph_unit = (_graph_ptr->_screen_size.x) /(_graph_ptr->_num_of_points - 1);
    Vector<sf::Vector2f> screen_points(_graph_points.size());
    for (double i = 0; i < screen_points.size(); i++){
        screen_points[i].x = screen_origin.x + _graph_points[i].x * (graph_unit/delta);
        screen_points[i].y = screen_origin.y - _graph_points[i].y * (graph_unit/delta);
    }
    return screen_points;
}

// Vector<sf::Vector2f> graph_to_screen(Vector<sf::Vector2f> graph_points, double delta){
//     //sf::Vector2f screen_origin(_graph_ptr->_screen_height / 2, _graph_ptr->_screen_width / 2);
//     double x_graph_unit = _graph_ptr->_screen_size.x / (_graph_ptr->_num_of_points - 1);
//     Vector<sf::Vector2f> screen_points(graph_points.size());
//     for (double i = 0; i < screen_points.size(); i++){
//         screen_points[i].x = _graph_ptr->_screen_origin.x + graph_points[i].x * x_graph_unit;
//         screen_points[i].y = _graph_ptr->_screen_origin.y - graph_points[i].y * x_graph_unit;
//     }
//     return screen_points;
// }

// sf::Vector2f get_screen_origin(){
//     return _screen_origin;
// }

void set_graph_ptr(GraphInfo* graph_ptr){
    _graph_ptr = graph_ptr;
}


Queue<Token*> get_postfix(){return _postfix;}



//sf::Vector2f points(float x, float y);

private:
    //string _equation;
    //Queue<Token*> _infix;
    Queue<Token*> _postfix;
    GraphInfo* _graph_ptr;
    Vector<sf::Vector2f> _graph_points;
    //sf::Vector2f _screen_origin;
};

#endif