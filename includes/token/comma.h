#ifndef COMMA_H
#define COMMA_H
#include <iostream>
#include <string>
#include "token.h"
using namespace std;

class Comma : public Token
{
public:
    Comma():Token(",", COMMA){
        _co = ",";
    }

    Comma(string co):Token(co, COMMA){
        _co = co;
    }

    TOKEN_TYPES TypeOf(){return COMMA;}

private:
    string _co;

};

#endif
