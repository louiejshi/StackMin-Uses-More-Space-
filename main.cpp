//
//  main.cpp
//  StackMin(Uses More Space)
//
//  Created by Louie Shi on 8/8/18.
//  Copyright © 2018 Louie Shi. All rights reserved.
//

#include <iostream>
#include <stack>
#include <algorithm>

#define invalid 100000000

using namespace std;

class NodeMin
{
    int val;
    int min;
    
public:
    NodeMin()
    {
        val = invalid;
        min = invalid;
    }
    
    NodeMin(int v, int m)
    {
        val = v;
        min = m;
    }
    
    int getVal()
    {
        return val;
    }
    
    void setVal(int v)
    {
        val = v;
    }
    
    int getMin()
    {
        return min;
    }
    
    void setMin(int m)
    {
        min = m;
    }
};



class stackWithMin: public stack<NodeMin>
{
    
public:
    int minimum()
    {
        if(empty())
        {
            return invalid;
        }
        else
        {
            NodeMin topNode = top();
            return topNode.getMin();
        }
    }

    void push(int v)
    {
        int newMin = min(v,minimum());
        NodeMin* nm = new NodeMin(v, newMin);
        stack<NodeMin>::push(*nm);
    }
    
    NodeMin PopandTop()
    {
        pop();
        NodeMin nm = top();
        return nm;
    }
};


int main(int argc, const char * argv[])
{
    stackWithMin stk;
    stk.push(5);
    cout << stk.minimum() << endl;
    
    stk.push(6);
    cout << stk.minimum() << endl;
    
    stk.push(3);
    cout << stk.minimum() << endl;
    
    stk.push(7);
    cout << stk.minimum() << endl;
    
    cout << endl;
    
    cout << stk.PopandTop().getMin() << endl;
    
    cout << stk.PopandTop().getMin() << endl;
    
    cout << stk.PopandTop().getMin() << endl;
    
    //cout << stk.PopandTop().getMin() << endl;
    
    return 0;
}
