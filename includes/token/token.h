#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>

using namespace std;

enum TOKEN_TYPES {INTEGER=0, DOUBLE, OPERATOR, LPAREN, RPAREN, FUNCTION, COMMA};

class Token
{
public:
    Token():_tk_str("UNINITIALIZED"){}
    Token(string Tok_str, TOKEN_TYPES type):_tk_str(Tok_str), _type(type){}
    friend ostream& operator <<(ostream& outs, Token* token_ptr){
        token_ptr->Print (outs);
        return outs;
    }
    virtual void Print(ostream& outs=cout){
        outs << "<" << _tk_str << ">";
    }
    virtual TOKEN_TYPES TypeOf(){return _type;}
private:
    string _tk_str;
    TOKEN_TYPES _type;
};

#endif