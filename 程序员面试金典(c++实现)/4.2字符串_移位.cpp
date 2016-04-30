#include<iostream>
#include<string>
using namespace std;
class Translation {
public:
    string stringTranslation(string A, int n, int len) {
        // write code here
        len%=n;
        severseString(A,0,len-1);
        severseString(A,len,n-1);
        severseString(A,0,n-1);
        return A;
    }
    void severseString(string& A, int left, int right) 
    {
        while(left <= right)
        {
            swap(A[left++], A[right--]); 
        }   
     }
};