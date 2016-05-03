#include<iostream>
#include<vector>
using namespace std;

class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        // write code here
        vector<int> help;
        while(!numbers.empty())
         {
              if(help.empty())
            {
                help.push_back(numbers.back());
                numbers.pop_back();
            }
            else
            {
                int temp = numbers.back();
                numbers.pop_back();
                while(!help.empty()&&help.back()>temp)
                {
                   numbers.push_back(help.back());
                   help.pop_back();
                }
               help.push_back(temp);
            }
         }
        while(!help.empty())
         {
            numbers.push_back(help.back());
            help.pop_back();
        }
        return numbers;
    }
};

void main()
{

}