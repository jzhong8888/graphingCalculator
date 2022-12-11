#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
#include "graph_info/graph_info.h"
#include "userInput.h"
class animate{
public:
    animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
    void step();
    void set_info(GraphInfo* graph_ptr);
    float get_graphpoint_x(float screen_point_x);
    float get_graphpoint_y(float screen_point_y);
    string userInput;
    sf::Text userText;
    bool enterText = false;
    int sb_enter_equation = 3; 
private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;         //The little red dot
    System system;                      //container for all the animated objects
    int command;                        //command to send to system
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    bool mouseIn;                       //mouse is in the screen
    Sidebar sidebar;                    //rectangular message sidebar
    GraphInfo* _info;
    //UserInput userInput;
    
};

string mouse_pos_string(sf::RenderWindow& window);



#endif // GAME_H
