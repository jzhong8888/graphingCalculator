#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "graph/graph.h"

using namespace std;
class System
{
public:
    System();
    System(GraphInfo* graph_ptr);
    void set_info(GraphInfo* graph_ptr);
    //void step(int command, GraphInfo* &graph_ptr);
    //void step(int command);
    void step(GraphInfo* graph_ptr, int command);
    int Size();
    void Draw(sf::RenderWindow& widnow, GraphInfo* &graph_ptr);
    //void Draw();
private:
//    vector<Particle> system;
    //sf::CircleShape shape;
    //sf::Vector2f vel;
    Graph _g;
    GraphInfo* _graph_ptr;
};

#endif // SYSTEM_H
