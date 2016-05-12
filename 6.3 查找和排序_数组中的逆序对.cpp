#include <iostream>
#include <vector>
using namespace std;
class AntiOrder {
public:
    void merge(vector<int>& A, int begin,int mid,int end,int& num)
    {
        
        int i = begin;
        int j = mid+1;
        int size = 0;  
        vector<int> temp(A);
        for(;(i<=mid)&&(j<=end);size++)
        {
            if(A[i]<A[j])
            {
                temp[size] = A[i++];
            }
            else
            {
                num+=mid-i+1;
                temp[size] = A[j++];
            }
       }
       while(i<=mid)
       {
           temp[size++] = A[i++];
       }
       while(j<=end)
       {
           temp[size++] = A[j++];
       }
       for(int i=0;i<size;i++)
       {
           A[begin+i] = temp[i];
       }
    }
    void mergesort(vector<int>& A, int begin,int end,int& num)
    {
        if(begin>=end) return;
        int mid = (begin+end)/2;
        mergesort(A,begin,mid,num);
        mergesort(A,mid+1,end,num);
        merge(A,begin,mid,end,num);
    }
    int count(vector<int> A, int n)
    {
        int num;
        mergesort(A,0,n-1,num);
        return num;
    }
};