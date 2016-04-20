#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Zipper {
public:
    string zipString(string iniString) 
	{
        // write code here
        int count = 1;
        string newIniString;
        for(int i=0;i<iniString.size();i++)
		{
            while(iniString[i]==iniString[i+1] && (i+1)<iniString.size())
			{
				count++; 
				i++;
            }
            newIniString+=iniString[i];
            newIniString+=intToStr(count);
			count = 1;
        }

        if(newIniString.size()>iniString.size())
		{
            return iniString;
        }
        return newIniString;
    }

   string intToStr(int &i)
   {
      string s;
	  stringstream ss(s);
	  ss << i;
	  return ss.str();
   }
};

void main22()
{
  Zipper demo;
  string str;
  str = demo.zipString("aabcccaaa");
  cout<<str<<endl;
}