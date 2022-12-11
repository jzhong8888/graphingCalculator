#include "animate.h"
#include "constants.h"
#include "graph_info/graph_info.h"
#include <iostream>
using namespace std;
#include "system.h"
#include "userInput.h"



/*
animate::animate():sidebar(WORK_PANEL, SIDE_BAR)

{
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will
    system = System();
    window.setFramerateLimit(60);

    mouseIn = true;




    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    cout<<"Geme CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    myTextLabel = sf::Text("Initial String for myTextLabel", font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setFillColor(sf::Color::Green);
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));







    cout<<"animate instantiated successfully."<<endl;
}
*/

animate::animate():sidebar(WORK_PANEL, SIDE_BAR){

    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
   
    
    _info = new GraphInfo();
    system.set_info(_info);
    
    window.setFramerateLimit(60);
    
    mouseIn = true;

    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    cout<<"Geme CTOR. preparing to load the font."<<endl;

    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    myTextLabel = sf::Text("Graphing Calculator", font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setFillColor(sf::Color::Green);
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));
    
    userText.setPosition(50, 50);
    userText.setFillColor(sf::Color::Green);
    userText = sf::Text("Press 'f' to enter an equation.", font);
    userText.setCharacterSize(20);
    userText.setStyle(sf::Text::Bold);
    // userInput = "f(x)=";

    //userInput.set_user_input("f(x)=");

    


    cout<<"animate instantiated successfully."<<endl;
}



void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    system.Draw(window, _info);
    
    if (mouseIn){
        window.draw(mousePoint);
    }

    sidebar.draw(window);

    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    window.draw(myTextLabel);

    window.draw(userText);
    //userInput.draw(window);
    //. . . . . . . . . . . . . . . . . . .
}

// void animate::set_info(GraphInfo* graph_ptr){
//     _info = graph_ptr;
//     system.set_info(graph_ptr);
// }

// void animate::step(){
//     //system.step(command, _info);
//     system.step(_info, command);
//     command = 0;
// }



void animate::update(){
    //cause changes to the data for the next frame
    system.step(_info, command);
    command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);

    }
}

void animate::render(){
       window.clear();
       Draw();
       //window.draw(userText);
       window.display();
}



void animate::processEvents()
{
   sf::Event event;
   float mouseX, mouseY;
   while (window.pollEvent(event))//or waitEvent
       {
       // check the type of the event...
           switch (event.type)
           {
           // window closed
           case sf::Event::Closed:
               window.close();
               break;

           // key pressed
           case sf::Event::KeyPressed:
               switch(event.key.code){
                case sf::Keyboard::Left:
                   sidebar[SB_KEY_PRESSED] = "PAN LEFT";
                   command = CMD_PAN_LEFT;
                //    _info->_domain.x = (_info->_domain.x) - 1;
                //    _info->_domain.y = (_info->_domain.y) - 1;
                   break;
                case sf::Keyboard::Right:
                   sidebar[SB_KEY_PRESSED] = "PAN RIGHT";
                   command = CMD_PAN_RIGHT;
                //    _info->_domain.x = (_info->_domain.x) + 1;
                //    _info->_domain.y = (_info->_domain.y) + 1;
                   break;
                case sf::Keyboard::Equal:
                   if(enterText == false){
                    sidebar[SB_KEY_PRESSED] = "ZOOM IN";
                    command = CMD_ZOOM_IN;
                   }
                //    _info->_domain.x = _info->_domain.x + 2;
                //    _info->_domain.y = _info->_domain.y - 2;
                break;
                case sf::Keyboard::Hyphen:
                   if (enterText == false){
                   sidebar[SB_KEY_PRESSED] = "ZOOM OUT";
                   command = CMD_ZOOM_OUT;
                   }
                //    _info->_domain.x = _info->_domain.x + 2;
                //    _info->_domain.y = _info->_domain.y - 2;
                break;
                case sf::Keyboard::Escape:
                   sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                   window.close();
                break;

                case sf::Keyboard::Enter:
                   sidebar[SB_KEY_PRESSED] = "ENTERED EQUATION";
                   _info->_equation = userInput;
                   enterText = false;
                   sidebar[sb_enter_equation] = userInput;
                   sb_enter_equation++;
                   //sidebar.history_equations.push_back(userInput);
                break;

                case sf::Keyboard::BackSpace:
                   sidebar[SB_KEY_PRESSED] = "BACKSPACE";
                   userInput.pop_back();
                   userText.setString(userInput);
                break;

                case sf::Keyboard::F:
                  sidebar[SB_KEY_PRESSED] = "ENTER EQUATION";
                  enterText = true;
                  userInput = "";
                  userText.setString(userInput);

                break;
                

                // case sf::Keyboard::F:
                //    sidebar[SB_KEY_PRESSED] = "ENTER EQUATION";
                //    command = CMD_ENTER_EQUATION;
                //    while(event.type == sf::Event::TextEntered){
                //     if (event.text.unicode < 128){
                //         userInput += event.text.unicode;
                //         userText.setString(userInput);
                //     }
                //    }
                   
                //    break;
            //       if (event.text.unicode < 128){
            //         userInput += event.text.unicode;
            //         userText.setString(userInput);
            //          //printf("%c", event.text.unicode);
            //       }
                
                
               }
                

               break;

           case sf::Event::MouseEntered:
               mouseIn = true;
               break;

           case sf::Event::MouseLeft:
               mouseIn = false;
               break;

           case sf::Event::MouseMoved:
                // mouseX = get_graphpoint_x(event.mouseMove.x);
                // mouseY = get_graphpoint_y(event.mouseMove.y);
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                //Do something with it if you need to...
               break;
           case sf::Event::MouseButtonReleased:
                   if (event.mouseButton.button == sf::Mouse::Right)
                   {
                       sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                               mouse_pos_string(window);

                   }
                   else{
                       sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                               mouse_pos_string(window);
                   }
                   break;

           case sf::Event::TextEntered:
                  if(enterText == true){
                    if (event.text.unicode < 128 && event.text.unicode != 8 && event.text.unicode != 'f' && event.text.unicode != 'F'){
                        userInput += event.text.unicode;
                        userText.setString(userInput);
                     //printf("%c", event.text.unicode);
                     }
                  }
                //   else if (event.text.unicode == 59){
                //     userInput.pop_back();
                //     userText.setString(userInput);
                //   }
                  //command = CMD_ENTER_EQUATION;
                  //_info->_equation = userInput.;
                  break;

           default:
                  break;
            
            
                 
           }
       }
}

float animate::get_graphpoint_x(float screen_point_x){
    double delta = (_info->_domain.y - _info->_domain.x) / (_info->_num_of_points - 1) - 0.0000000000001;
    float graphpoint_x;
    double graph_unit = _info->_screen_size.x / (_info->_num_of_points - 1);
    double screen_origin_x = (0 + (0 - _info->_domain.x))* (graph_unit/delta);
    graphpoint_x = (screen_point_x - screen_origin_x) / (graph_unit/delta);
    return graphpoint_x;
}

float animate::get_graphpoint_y(float screen_point_y){
    double delta = (_info->_domain.y - _info->_domain.x) / (_info->_num_of_points - 1) - 0.0000000000001;
    float graphpoint_y;
    double graph_unit = _info->_screen_size.x / (_info->_num_of_points - 1);
    double screen_origin_y = _info->_screen_size.y / 2;
    graphpoint_y = (screen_point_y - screen_origin_y) / (graph_unit/delta);
    return graphpoint_y;
}

// void enterEquation(){

// }

void animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}
