#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Remove
{
public:
	bool removeNode(ListNode *pNode)
	{
		if(pNode->next==NULL)
		{
			return false;
		}
		pNode->val = pNode->next->val;
		return true;
	}
};
void main33()
{
  system("pause");
}