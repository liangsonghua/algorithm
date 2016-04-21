#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  struct ListNode *next;
  ListNode(int x = 0):
  val(x),next(NULL){
  }
};
/*
第一次遍历链表，第一次求链表的长度length,第二次求第length-k+1个结点
*/
class Solution
{
public:
  ListNode* FindKthToTail(ListNode* pListHead,unsigned int k)
  {
    ListNode *p = pListHead;
	unsigned int length = 0;
	while(p)
	{
	  length++;
	  p = p->next;
	}
	if(k>length)return NULL;
	unsigned int temp = 1;
	while(p)
	{
	   if(temp == length-k+1){
		  return p;
		}
	  temp++;
	  p = p->next;
	}
	return NULL;
  }
};
void main22()
{
  system("pause");
}