#include <iostream>
using namespace std;
typedef struct tagSBucket
{
  bool bValid;
  int nMin;
  int nMax;
  tagSBucket():bValid(false){}
  void Add(int n)//将数n加入到桶中
  {
	  if(!bValid)
	  {
	    nMin = nMax = n;
		bValid = true;
	  }
	  else
	  {
		  if(nMax<n)
               nMax = n;
		  else if(nMin > n)
			  nMin = n;
	  }
  }
}SBucket;

int CalcMaxGap(const int* A,int size)
{
	SBucket* pBucket = new SBucket[size];
	int nMax = A[0];
	int nMin = A[0];
	int i;
	for(int i=1;i<size;i++)
	{
	   if(nMax<A[i])
               nMax = A[i];
		  else if(nMin > A[i])
			  nMin = A[i];
	}
	//依次将数据放入
	int delta = nMax-nMin;
	int nBucket;//某数应该在哪个桶中
	for(i=0;i<size;i++)
	{
	   nBucket = (A[i]-nMin)*size/delta;
	   if(nBucket>=size){
	     nBucket = size-1;
	   }
	   pBucket[nBucket].Add(A[i]);
	}
	//计算有效桶的间隔
	i = 0;//第一个肯定是有效的
	int nGap = 0;//最小间隔
	int gap;
	//i是前一个桶，j是后一个桶
	for(int j=1;j<size;j++)
	{
		if(pBucket[j].bValid)
		{
			gap = pBucket[j].nMin-pBucket[i].nMax;
			if(nGap < gap)
			{
			  nGap = gap;
			}
			i = j;
		}
	}
	return nGap;
}