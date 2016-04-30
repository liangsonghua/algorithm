#include<iostream>
#include<vector>
using namespace std;
class MinCost {
public:
    int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
        // write code here
        /*
        (1) 必须S[i] == T[j], 这时前i – 1和j – 1位都已经对齐了，这部分肯定要最少扣分。这种情况下最少的扣分是f(i-1,j-1)
        (2) 和（1）类似，S[i]≠T[j]，这种情况下最少的扣分是f(i -1, j – 1) + 1
        (3) S的前i位和T的前（j – 1）位已经对齐了，这部分扣分也要最少。这种情况下最少的扣分是f(i,j-1) + 1
        (4) S的前(i-1)位已经和T的前j位对齐了，这部分扣分要最少。这种情况下最少的扣分是f(i,j-1) + 1
        
        */
        if(n <= 0 || m <= 0)
            return 0;
        vector< vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i < n + 1; i++)
            dp[i][0] = c1 * i;
        for(int j = 1; j < m + 1; j++)
            dp[0][j] = c0 * j;
         
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < m + 1; j++)
            {
                if(A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j - 1] + c2;
                dp[i][j] = min(dp[i][j - 1] +  c0, dp[i][j]);
                dp[i][j] = min(dp[i - 1][j] +  c1, dp[i][j]);
            }
        }
        return dp[n][m];
    }
};