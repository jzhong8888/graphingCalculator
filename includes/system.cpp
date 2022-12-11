


#include "system.h"
#include "random.h"
#include "graph_info/graph_info.h"
#include "graph/graph.h"

#include <iostream>

#include "constants.h"
/*
System::System()
{
    Random r;
    int xpos = 100;
    int ypos = 100;
    //the shape of the object, along with its velocity, acceleration,
    //position, etc. should be part of the individual object.
    shape = sf::CircleShape(10);
    shape.setPosition(sf::Vector2f(xpos, ypos));
    vel = sf::Vector2f(r.Next(-5,5), r.Next(-5,5)); //random velocity
    int r_ = r.Next(0,255);
    int g_ = r.Next(0,255);
    int b_ = r.Next(0,255);
    shape.setFillColor(sf::Color(r_, g_, b_));

}
*/

System::System(){
    GraphInfo* graph_ptr = nullptr;
}

System::System(GraphInfo* graph_ptr){
    //Graph g;
    //_g = Graph();
    _graph_ptr = graph_ptr;
    _g.set_info(graph_ptr);
    //Vector<sf::Vector2f> screen_points = _g.get_screen_points();
}

void System::set_info(GraphInfo* graph_ptr){
    _graph_ptr = graph_ptr;
    _g.set_info(graph_ptr);
}


//------------------------------------------------------------------
//------------------------------------------------------------------


/*
void System::Step(int command){

        //all this is the responsibility of the
        // individual object:
        shape.move(vel);
        sf::Vector2f pos = shape.getPosition();
        if ((pos.x)>=WORK_PANEL-20)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if (pos.x<=0)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if ((pos.y)>=SCREEN_HEIGHT-20)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
        if (pos.y<=0)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);

}
*/



void System::step(GraphInfo* graph_ptr, int command){
    
    if (command == CMD_PAN_LEFT){
        graph_ptr->_domain.x -= 1;
        graph_ptr->_domain.y -= 1;
    }
    else if (command == CMD_PAN_RIGHT){
        (graph_ptr->_domain.x) += 1;
        (graph_ptr->_domain.y) += 1;
    }
    else if (command == CMD_ZOOM_IN){
        if (graph_ptr->_domain.y - graph_ptr->_domain.x > 2){
        (graph_ptr->_domain.x) += 1;
        (graph_ptr->_domain.y) -= 1;
        }
    }
    else if (command == CMD_ZOOM_OUT){
        graph_ptr->_domain.x -= 1;
        graph_ptr->_domain.y += 1;
    }
    // else if (command == CMD_ENTER_EQUATION){
    //     graph_ptr->_equation = 
    // }
    // _graph_ptr = graph_ptr;
    // _g.update(graph_ptr);
}


void System::Draw(sf::RenderWindow& window, GraphInfo* &graph_ptr){
    //set_info(graph_ptr);
    //window.clear();
    //window.draw(shape);
    //_g.update(graph_ptr);
    _g.draw(window, graph_ptr);

}

/*
void System::Draw(){
    //_g.update();  ???
    _g.draw();
}
*/

