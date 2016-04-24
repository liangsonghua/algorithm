#include<iostream>
using namespace std;
class Compare {
public:
    int getMax(int a, int b) {
        // write code here
       // 我们可以得到a-b的符号，根据该符号决定返回a或b
           int c=a-b;
           int flag=((c>>31)&1^1);
           int flag_inv=1-flag;
           return flag*a+flag_inv*b;
    }
};