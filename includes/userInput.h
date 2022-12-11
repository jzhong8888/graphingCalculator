#ifndef USER_INPUT_H
#define USER_INPUT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UserInput
{
public:
    UserInput(){
        _userInput = "f(x) =";
    }

    void push_back(char add_me){
        _userInput += add_me;
    }

    string get_user_input(){
        return _userInput;
    }

    void set_user_input(string userInput){
        _userInput = userInput;
    }

    void draw(sf::RenderWindow& window){
        sf::Text userText;

        // userText.setPosition(50, 50);
        // userText.setFillColor(sf::Color::Green);
        // //userText = sf::Text(_userInput, font);
        // userText.setCharacterSize(20);
        // userText.setStyle(sf::Text::Bold);
        //userText.setFont(front);
        userText.setString(_userInput);
        window.draw(userText);
    }

private:
    string _userInput;
};

#endif