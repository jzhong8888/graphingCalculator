#ifndef OPERATOR_H
#define OPERATOR_H
#include <iostream>
#include <string>
#include "token.h"
using namespace std;

class Operator : public Token
{
public:
    Operator(string op):Token(op, OPERATOR){
        _precedence = get_prec();
        _op = op;
    }

    virtual int get_prec(){
        if (_op == "+" || _op == "-"){
            return 2;
        }
        else if (_op == "*" || _op == "/"){
            return 3;
        }
        else if (_op == "^"){
            return 4;
        }
        return 0;
    }

    int precedence(){return _precedence;}

    bool isLeftAssociative(){
        if (_op == "+" || _op == "-"){
            return true;
        }
        else if (_op == "*" || _op == "/"){
            return true;
        }
        else if (_op == "!"){
            return true;
        }
        else {
            return false;
        }
    }

    void Print(ostream& outs){
        outs << "[" << _op << "]";
    }

    TOKEN_TYPES TypeOf(){return OPERATOR;}

    string op(){return _op;}



private:
    int _precedence;
    string _op;
};

#endif