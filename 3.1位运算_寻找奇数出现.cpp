#include<iostream>
#include<vector>
using namespace std;
class OddAppearance {
public:
    int findOdd(vector<int> A, int n) {
        // write code here
        unsigned int ec = 0;
        for(int i=0;i<n;i++)
        {
            ec ^= A[i];
        }
        return ec;
    }
};