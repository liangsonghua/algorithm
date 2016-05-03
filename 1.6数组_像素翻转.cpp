/*
 思路：第一步：先将矩阵以次对角线互换 （如果是逆时针则为主对角线）
       第二步：交换第i行到第n-i-1行
*/
class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        // write code here
      int temp;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n-i-1;j++)
          {
             temp = mat[i][j];
             mat[i][j] = mat[n-j-1][n-i-1];
             mat[n-j-1][n-i-1] = temp;
          }
      }
      for(int i=0;i<n/2;i++)
      {
          for(int j=0;j<n;j++)
          {
             temp = mat[i][j];
             mat[i][j] = mat[n-i-1][j];
             mat[n-i-1][j] = temp;
          }
        
      }
     return mat;
    }
};