#include <iostream>
using namespace std;
void Holland(int*a ,int length)
{
  int begin = 0;
  int current = 0;
  int end = length-1;
  while(current <= end)
  {
	  if(a[current] == 2)
	  {
	    swap(a[end],a[current]);
		end--;
	  }
	  else if(a[current] == 1)
	  {
	    current++;
	  }
	  else
	  {
		  /*
		  if(begin != current)
		  {
		    swap(a[current],a[begin]);
		  }
		    begin++;
			current++;
		  */
		  if(begin == current)
		  {
		    begin++;
			current++;
		  }
		  else
		  {
		    swap(a[current],a[begin]);
			begin++;
		  }
	  }
  }
}