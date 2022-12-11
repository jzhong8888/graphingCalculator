#ifndef INTEGER_H
#define INTEGER_H
#include <string>
#include "token.h"
using namespace std;

class Integer : public Token
{
public:
    Integer(double num):Token(to_string(num), INTEGER), _num(num){}
    Integer(string num):Token(num, INTEGER), _num(atof(num.c_str())){}
    void Print(ostream& outs){
        outs << "[" << _num << "]";
    }
    TOKEN_TYPES TypeOf(){return INTEGER;}
    double Num(){return _num;}
private:
    double _num;

};

#endif // INTEGER_H