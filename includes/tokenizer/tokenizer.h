#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <string>
#include <map>
#include <stack>
#include <cmath>
#include <cassert>
#include <cstring>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <cctype>

#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/token.h"
#include "../token/operator.h"
#include "../token/integer.h"
#include "../token/function.h"
#include "../token/leftparen.h"
#include "../token/rightparen.h"
#include "../token/comma.h"

using namespace std;

class Tokenizer
{
public:
    Tokenizer(){
        _equation = "";
    }

    Tokenizer(string &equation){
        _equation = equation;
    }

    string toUpper(string str){
        string result;
        for (int i = 0; i < str.size(); i++){
            result[i] = toupper(str[i]);
        }
        return result;
    }

    Queue<Token*> infix(string &equation){
        int j;
        string temp;
        Queue<Token*> infix;

        for (int i = 0; i < equation.size(); i++){
            if (isdigit(equation[i]) == true || equation[i] == '.'){
                temp = equation[i];
                j = i + 1;
                while(isdigit(equation[j]) == true || equation[j] == '.'){
                    temp += equation[j];
                    j++;
                }
                infix.push(new Integer(temp));
                i = j - 1;
            }
            else if (isalpha(equation[i])){
                temp = equation[i];
                j = i + 1;
                while(isalpha(equation[j])){
                    temp += equation[j];
                    j++;
                }
                // Capitalize all the character in the string temp.
                //temp = toUpper(temp);
                //transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
                for (int k = 0; k < temp.size(); k++){
                    temp[k] = toupper(temp[k]);
                }

                infix.push(new Function(temp));
                i = j - 1;
            }
            else if (equation[i] == ','){
                temp = equation[i];
                infix.push(new Comma(temp));
            }
            else if (equation[i] == '(' || equation[i] == '[' || equation[i] == '{'){
                temp = equation[i];
                infix.push(new LeftParen(temp));
            }
            else if (equation[i] == ')' || equation[i] == ']' || equation[i] == '}'){
                temp = equation[i];
                infix.push(new RightParen(temp));
            }
            else if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/' || equation[i] == '^'){
                temp = equation[i];
                infix.push(new Operator(temp));
            }
        }
        return infix;
    }

    Queue<Token*> infix(){
        int j;
        string temp;
        Queue<Token*> infix;

        for (int i = 0; i < _equation.size(); i++){
            //int x = 0;
            if (isdigit(_equation[i]) == true || _equation[i] == '.'){
                //x = 2;
                //cout << x << endl;
                temp = _equation[i];
                j = i + 1;
                while(isdigit(_equation[j]) == true || _equation[j] == '.'){
                    temp += _equation[j];
                    j++;
                }
                infix.push(new Integer(temp));
                i = j - 1;
            }
            else if (isalpha(_equation[i])){
                //x = 1;
                //cout << x << endl;
                temp = _equation[i];
                //cout << temp << endl;
                j = i + 1;
                while(isalpha(_equation[j])){
                    temp += _equation[j];
                    j++;
                }
                //cout << temp << endl;
                // Capitalize all the character in the string temp.
                //transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
                
                for (int k = 0; k < temp.size(); k++){
                    temp[k] = toupper(temp[k]);
                }
                infix.push(new Function(temp));
                i = j - 1;
            }
            else if (_equation[i] == ','){
                temp = _equation[i];
                infix.push(new Comma(temp));
            }
            else if (_equation[i] == '(' || _equation[i] == '[' || _equation[i] == '{'){
                temp = _equation[i];
                infix.push(new LeftParen(temp));
            }
            else if (_equation[i] == ')' || _equation[i] == ']' || _equation[i] == '}'){
                temp = _equation[i];
                infix.push(new RightParen(temp));
            }
            else if (_equation[i] == '+' || _equation[i] == '-' || _equation[i] == '*' || _equation[i] == '/' || _equation[i] == '^'){
                temp = _equation[i];
                infix.push(new Operator(temp));
            }
        }
        return infix;
    }

    void equation (string &equation){
        _equation = equation;
    }

private:
    string _equation;
};

#endif
