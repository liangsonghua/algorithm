#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//要求时间复杂度O(N)空间复杂度O(1)
int removeBlank(char *pString){
  //两个游标
	int j = 0;
	for(int i=0;pString[i]!='\0';i++)
	{
		if(pString[i]!=' ')
		{
			if(i!=j)
			{
			  pString[j] = pString[i];
			}
		   j++;
		}
	}
	pString[j] = 0;
	return 0;
}

int main()
{
  char str[] = "i have a dream";
  removeBlank(str);
  cout<<str<<endl;
  system("pause");
  return 0;
}