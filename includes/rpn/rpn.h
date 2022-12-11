#ifndef RPN_H
#define RPN_H

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


using namespace std;

class RPN
{
public:

// constructor
RPN(Queue<Token*> &postfix){
    _postfix = postfix;
}


// set_input(postfix)
void set_input (Queue<Token*> &postfix){
    _postfix = postfix;
}

double operator()(const double &value=0){
    Stack<double> output;
    
    while(!_postfix.empty()){
        Token* temp = _postfix.pop();
        if (temp->TypeOf() == OPERATOR){
            assert(output.size() >= 2);
            double rhs = output.top();
            output.pop();
            double lhs = output.top();
            output.pop();
            string opera = static_cast<Operator*>(temp)->op();
      
            output.push(eval(lhs, rhs, opera));
        }
        else if(temp->TypeOf() == FUNCTION){
            int num_of_argu;
            num_of_argu = static_cast<Function*>(temp)->get_argu();
            if (num_of_argu == 1)
            {
            assert(output.size() >= 1);
            double num = output.top();
            output.pop();
            string func = static_cast<Function*>(temp)->fun();
            output.push(eval_fun(num, func));
            }
            else if (num_of_argu == 2){
                assert (output.size() >= 2);
                double num2 = output.top();
                output.pop();
                double num1 = output.top();
                output.pop();
                string func = static_cast<Function*>(temp)->fun();
                output.push(eval_fun(num1, num2, func));
            }
            else if (num_of_argu == -1){
                double num = value;
                output.push(num);
            }
            else if (num_of_argu == 0){
                output.push(3.141592653589793);
            }
        }
        else if (temp->TypeOf() == INTEGER){
            double num = static_cast<Integer*>(temp)->Num();
            output.push(num);
        }
        
    }
    //cout << output << endl;
    assert(output.size() == 1);
    return output.top();
}


double eval (double lhs, double rhs, string opera){
    double result;
    if (opera == "+"){
        result = lhs + rhs;
    }
    else if (opera == "-"){
        result = lhs - rhs;
    }
    else if (opera == "*"){
        result = lhs * rhs;
    }
    else if (opera == "/"){
        result = lhs / rhs;
    }
    else{
        result = pow(lhs, rhs);
    }
    return result;
}

double eval_fun (double num, string fun){
    double result;
    if (fun == "SIN"){
        result = sin(num);
    }
    else if (fun == "COS"){
        result = cos(num);
    }
    else if (fun == "TAN"){
        result = tan(num);
    }
      else if (fun == "COT"){
        result = cos(num)/sin(num);
    }
    return result;
}

double eval_fun (double num1, double num2, string fun){
    
    if (fun == "MAX"){
        if(num1 >= num2){
            return num1;
        }
        else{
            return num2;
        }
    }
    else if (fun == "MIN") {
        if (num1 <= num2){
            return num1;
        }
        else{
            return num2;
        }
    }
    
}


private:
    Queue<Token*> _postfix;
};




#endif