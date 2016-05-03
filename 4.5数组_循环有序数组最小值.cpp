#include <iostream>
#include <vector>
using namespace std;
class MinValue {
public:
    int getMin(vector<int> arr, int n) {
        // write code here
        int left = 0;
        int right = n-1;
        int mid = 0;
        while(left<right)
        {
            mid = (left+right)/2;
            if(arr[mid]<arr[right])
            {
                //¶ªÆúºó¶Î
               right = mid; 
            }
            else
            {
                left = mid+1;
            }
        }
       return arr[left];
    }
};