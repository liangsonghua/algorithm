#include <vector>
#include <iostream>
using namespace std;
/*
以ai结尾的最长递增子序列记做Li,其长度记为b[i]
b[i] ={max(b[j])+1,0<=j<i且aj<ai}

*/
class AscentSequence {
public:
    int findLongest(vector<int> A, int n) {
        // write code here
        vector<int> dp(n);
		dp[0] = 1;
		int maxLen = dp[0];
		for (int i = 1; i < n; ++i) {
			maxLen = 1;
			for (int j = 0; j < i; ++j) {
				if (A[j] < A[i]) {
					maxLen = max(maxLen, dp[j] + 1);
				}
			}
			dp[i] = maxLen;
		}
		for (int i = 0; i < n; ++i) {
			maxLen = max(maxLen, dp[i]);
		}
		return maxLen;
    }
};