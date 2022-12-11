

#include <iostream>
#include "includes/animate.h"
using namespace std;

int main()
{
    animate game;
    game.run();
    cout<<endl<<endl<<"------ MAIN EXITING --------------------------"<<endl;
    return 0;
}


/*

#include <iostream>
#include <iomanip>

#include "./includes/token/token.h"
#include "./includes/token/integer.h"
#include "./includes/token/operator.h"
#include "./includes/queue/MyQueue.h"

#include "./includes/token/function.h"
#include "./includes/token/leftparen.h"
#include "./includes/token/rightparen.h"

#include "./includes/queue/MyQueue.h"

#include "./includes/shunting_yard/shunting_yard.h"
#include "./includes/rpn/rpn.h"
#include "./includes/plot/plot.h"
#include "./includes/graph_info/graph_info.h"


using namespace std;

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;
    //phase 0'
    

    Token *t = new Token();
    cout << "here is a token" << t << endl;

    Token* tkptr = new Integer(42);
    cout << "here is the number: " << tkptr << endl;
    tkptr = new Operator ("*");
    cout << "here is the operator: " << tkptr<< endl;


    Queue<Token*> infix;
    infix.push(new Integer(3));
    infix.push(new Operator("*"));
    infix.push(new Function("SIN"));
    infix.push(new Integer(8));
    infix.push(new Operator("+"));
    infix.push(new Integer(6));
    infix.push(new Operator("/"));
    infix.push(new LeftParen());
    infix.push(new Integer(8));
    infix.push(new Operator("+"));
    infix.push(new Integer(3));
    infix.push(new RightParen());
    ShuntingYard sy(infix);
    Queue<Token*> postfix = sy.postfix();
    for (Queue<Token *>::Iterator it = postfix.begin(); it != postfix.end(); it++){
    cout <<setw(3)<< *it;
    }
    cout << endl;

    Queue<Token*> infix2;
    infix2.push(new Function("X"));
    infix2.push(new Operator("^"));
    infix2.push(new Integer(2));

    GraphInfo* gi_ptr = new GraphInfo(-4, 8, 13, 600, 600);

    
    Plot plot(infix2, gi_ptr);
    Queue<Token*> postf = plot.get_postfix();

    for (Queue<Token *>::Iterator it = postf.begin(); it != postf.end(); it++){
    cout <<setw(3)<< *it;
    }
    cout << endl;

    Vector<sf::Vector2f> points = plot();
    cout << "points size: " << points.size() << endl;
    for (int i = 0; i < points.size(); i++){
        cout << "(" << points[i].x << "," << points[i].y << ") ";
    }
    cout << endl;

    




    cout << "\n\n\n=====================" << endl;
    return 0;
}


*/