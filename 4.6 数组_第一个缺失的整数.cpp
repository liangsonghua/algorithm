#include <iostream>
using namespace std;
int FirstMissNumber(int* a,int size)
{
   a--;//从1开始计数
   int i = 1;
   while(i <= size)
   {
	   if(a[i] == i)
	   {
	     i++;
	   }
	   else if((a[i] < i)||(a[i]>size)||(a[a[i]] = a[i]))
	   {
	     a[i] = a[size];
		 size--;
	   }
	   else
	   {
	     swap(a[a[i]],a[i]);
	   }
   }
}