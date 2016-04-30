#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        // write code here
        //从后往前维护一个栈
        stack<int> stack;
        vector<int> result;
        stack.push(-1);//最右边第一个没有下一个较大元素
        //如果当前栈为空则直接入栈
        //不为空则弹出top，如果top元素大于当前元素则为较大元素
        //如果top元素小于当前元素，则继续弹出直到-1或者大于当前元素
        for(int i=n-1;i>=0;--i)
        {
            int top = stack.top();
            while(top!=-1&&A[i]>=top)
            {
                stack.pop();
                top = stack.top();
            }
			
            result.insert(result.begin(),top);
            stack.push(A[i]);
        }
        return result;
    }
};