#include<iostream>
#include <vector>
using namespace std;
 
int maxPath(vector<vector<int> > &num) {
	
    unsigned int m = num.size();
    vector<vector<int> > sum;
	sum[0][0] = num[0][0];
	for(int i=0;i<m;++i)
	{
		 for(int j=0;j<m;++j)
		{
				sum[i][j]=max(sum[i-1][j],sum[i][j-1])+num[i][j];
		}
	}
    return sum[m-1][m-1];
}