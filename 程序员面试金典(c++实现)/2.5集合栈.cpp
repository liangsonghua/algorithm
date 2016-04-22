#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SetOfStacks {
public:
    vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
        // write code here
         vector<vector<int> > st;
        vector<int> temp;
        for(int i=0;i<ope.size();i++)
        {
            if(ope[i][0] == 1)
            {
                //入栈
                if(temp.size() == size)
                {
                    //栈满，则新建一个栈，再入栈
                    st.push_back(temp);
                    temp.clear();
                    temp.push_back(ope[i][1]);
                }
                else
                    temp.push_back(ope[i][1]);
            }
            if(ope[i][0] == 2)
            {
                //出栈
                if(temp.size() != 0)//当前栈不为空，直接出栈
                    temp.pop_back();
                else if(st.size() != 0)
                {
                    //当前栈为空，则从上一个栈出
                    temp=st[st.size()-1];
                    temp.pop_back();
                    st.pop_back();
                }
            }
        }
        if(temp.size() != 0)
        {
            st.push_back(temp);
        }
        return st;
    }
};