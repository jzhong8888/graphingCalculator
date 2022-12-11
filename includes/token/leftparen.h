#ifndef LEFTPAREN_H
#define LEFTPAREN_H
#include <iostream>
#include <string>
#include "token.h"
using namespace std;

class LeftParen : public Token
{
public:
    LeftParen():Token("(", LPAREN){
        _lp = "(";
    }

    LeftParen(string lp):Token(lp, LPAREN){
        if (lp == "(" || lp == "[" || lp == "{"){
            _lp = lp;
        }
        else{
            _lp = "(";
        }
    }

    TOKEN_TYPES TypeOf(){return LPAREN;}

private:
    string _lp;
};

#endif