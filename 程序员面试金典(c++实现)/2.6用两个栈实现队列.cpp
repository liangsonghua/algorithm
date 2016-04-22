#include<iostream>
#include<stack>
using namespace std;
class Solution
{
    //先来先出
    //进时，栈2是否为空，不为空，则栈2元素倒回到栈1，出时，将栈1元素全部弹到栈2中，直到栈1为空。
public:
    void push(int node) {
        while(!stack2.empty()){
           stack1.push(stack2.top()); 
           stack2.pop();
        }
        stack1.push(node);
    }

    int pop() {  
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }  
        int result = stack2.top();
        stack2.pop();
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};