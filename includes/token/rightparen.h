#ifndef RIGHTPAREN_H
#define RIGHTPAREN_H
#include <iostream>
#include <string>
#include "token.h"
using namespace std;

class RightParen : public Token
{
public:
    RightParen():Token(")", RPAREN){
        _rp = ")";
    }

    RightParen(string rp):Token(rp, RPAREN){
        if (rp == ")" || rp == "]" || rp == "}"){
            _rp = rp;
        }
        else{
            _rp = ")";
        }
    }

    TOKEN_TYPES TypeOf(){return RPAREN;}

private:
    string _rp;
};

#endif