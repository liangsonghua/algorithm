#include <iostream>
#include <vector>
using namespace std;
void LCS(const char* str1,const char* str2,string& str)
{
  int size1 = (int)strlen(str1);
  int size2 = (int)strlen(str2);
  const char* s1 = str1-1;//从1开始数
  const char* s2 =str2-1;
  vector<vector<int> >chess(size1+1,vector<int>(size2+1));
  int i,j;
  for(i=0;i<=size1;i++)
  {
    chess[i][0]
  }
  for(i=1;i<=size1;i++)
  {
	   for(j=1;j<=size2;j++)
	  {
          
	  }
  }
}
int main()
{
  const char* str1 ="TCGGATCGACTT";
  const char* str2 = "AGCCTACGTA";
  string str;
  LCS(str1,str2,str);
  cout<<str.c_str()<<endl;
  return 0;
}