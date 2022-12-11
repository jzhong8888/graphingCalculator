#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include <vector>
#include <string>
#include <map>
#include <stack>
#include <cmath>
#include <cassert>

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

class ShuntingYard
{
public:

ShuntingYard(){
    Queue<Token*> infix;
    _infix = infix;
}

// constructor
ShuntingYard(Queue<Token*> &infix){
    _infix = infix;
}

Queue<Token*> postfix(Queue<Token*> &infix){
    Queue<Token*> postfix;
    Stack<Token*> opera;
    
    while (!infix.empty()){
        Token* temp = infix.pop();
        if(temp->TypeOf() == INTEGER){
            postfix.push(temp);
        }
        else if(temp->TypeOf() == FUNCTION){
            opera.push(temp);
        }
        else if(temp->TypeOf() == OPERATOR){
            while((!opera.empty() && opera.top()->TypeOf() != LPAREN) && (
            (static_cast<Operator*>(opera.top())->get_prec() > static_cast<Operator*>(temp)->get_prec())
            || ((static_cast<Operator*>(opera.top())->get_prec() == static_cast<Operator*>(temp)->get_prec())
            &&(static_cast<Operator*>(temp)->isLeftAssociative() == true))
            )
            )
            {
                Token* o2 = opera.pop();
                postfix.push(o2);
            }
        
            opera.push(temp);
        }
        else if(temp->TypeOf() == LPAREN){
            opera.push(temp);
        }
        else if(temp->TypeOf() == RPAREN){
            while(opera.top()->TypeOf() != LPAREN){
                /* If the stack runs out without finding a left parenthesis, then there are mismatched parentheses. */
                assert (opera.empty() == false);
                
                Token* oper = opera.pop();
                postfix.push(oper);
            }
            assert (opera.top()->TypeOf() == LPAREN);
            opera.pop();
            if (!opera.empty() && opera.top()->TypeOf() == FUNCTION){
                
                Token* func = opera.pop();
                postfix.push(func);
            }
        }
        else if (temp->TypeOf() == COMMA){
            temp = infix.pop();
        }
    
    }
    while(!opera.empty()){
        assert (opera.top()->TypeOf() != LPAREN);
       
        Token* ope = opera.pop();
        postfix.push(ope);
    }
    return postfix;

}

Queue<Token*> postfix(){
    Queue<Token*> postfix;
    Stack<Token*> opera;
    
    
    while (!_infix.empty()){
        Token* temp = _infix.pop();
        if(temp->TypeOf() == INTEGER){
            postfix.push(temp);
        }
        else if(temp->TypeOf() == FUNCTION){
            opera.push(temp);
        }
        else if(temp->TypeOf() == OPERATOR){
            while((!opera.empty() && opera.top()->TypeOf() != LPAREN) && (
            (static_cast<Operator*>(opera.top())->get_prec() > static_cast<Operator*>(temp)->get_prec())
            || ((static_cast<Operator*>(opera.top())->get_prec() == static_cast<Operator*>(temp)->get_prec())
            &&(static_cast<Operator*>(temp)->isLeftAssociative() == true))
            )
            )
            {
                Token* o2 = opera.pop();
                postfix.push(o2);
            }
        
            opera.push(temp);
        }
        else if(temp->TypeOf() == LPAREN){
            opera.push(temp);
        }
        else if(temp->TypeOf() == RPAREN){
            while(opera.top()->TypeOf() != LPAREN){
                /* If the stack runs out without finding a left parenthesis, then there are mismatched parentheses. */
                assert (opera.empty() == false);
                
                Token* oper = opera.pop();
                postfix.push(oper);
            }
            assert (opera.top()->TypeOf() == LPAREN);
            opera.pop();
            if (!opera.empty() && opera.top()->TypeOf() == FUNCTION){
                
                Token* func = opera.pop();
                postfix.push(func);
            }
        }
        else if (temp->TypeOf() == COMMA){
            temp = _infix.pop();
        }
    
    }
    while(!opera.empty()){
        assert (opera.top()->TypeOf() != LPAREN);
       
        Token* ope = opera.pop();
        postfix.push(ope);
    }
    return postfix;

}

void infix (Queue<Token*> &infix){
    _infix = infix;
}

private:
    Queue<Token*> _infix;

};

#endif