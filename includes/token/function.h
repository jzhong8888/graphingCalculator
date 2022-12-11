#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <string>
#include "token.h"
using namespace std;

class Function : public Operator
{
public:
    Function(string fun):Operator(fun){
        _precedence = get_prec();
        _fun = fun;
        _numOfArgument = get_argu();
    }

    int get_prec(){
        return 99;
    }

    int get_argu(){
        if (_fun == "SIN" || _fun == "COS" || _fun == "TAN" || _fun == "COT"){
            return 1;
        }
        else if (_fun == "PI"){
            return 0;
        }
        else if (_fun == "MAX" || _fun == "MIN"){
            return 2;
        }
        else{
            return -1;
        }
    }



    TOKEN_TYPES TypeOf(){return FUNCTION;}

    string fun(){return _fun;}


private:
    int _numOfArgument;
    int _precedence;
    string _fun;

};

#endif