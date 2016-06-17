#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int letter[12] = { 0 };
		int bad = 0;//记录有几次天平不平衡
		for (int i = 0; i < 3; i++)
		{
			string a, b, c;
			cin >> a >> b >> c;
			if (c == "up")
			{
				for (int j = 0; j < a.size(); j++)
					letter[a[j] - 65] ++;//左边重的都+1
				for (int j = 0; j < b.size(); j++)
					letter[b[j] - 65] --;//右边轻的都-1
				bad++;//不平衡次数+1
			}
			if (c == "down")
			{
				for (int j = 0; j < a.size(); j++)
					letter[a[j] - 65] --;
				for (int j = 0; j < b.size(); j++)
					letter[b[j] - 65] ++;
				bad++;
			}
			if (c == "even")
				for (int j = 0; j < a.size(); j++)
					letter[a[j] - 65] = letter[b[j] - 65] = 9; 
			//不一定非要是9  其实只要是一个比3大的数就行 因为最多有3次不平衡
		}
		for (int i = 0; i < 12; i++)
		{
			if (letter[i] == bad) //如果有一个有bad次++
				cout << char(i + 65) << " is the counterfeit coin and it is heavy." << endl;
			if (letter[i] == -bad)//如果有一个有bad次--
				cout << char(i + 65) << " is the counterfeit coin and it is light." << endl;
		}
	}	
	return 0;
}
