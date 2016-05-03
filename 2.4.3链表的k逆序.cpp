#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class KInverse {
public:
    ListNode* inverse(ListNode* head, int k) {
        // write code here
        //思路一:可以使用栈存储k个节点，然后依次弹出，需要额外的空间
        //思路二:不使用栈，但是需要前一次调整后的最后一个节点指针下一组需要调整的最后一个节点
        ListNode *p = head;
        ListNode *pre = NULL;
        ListNode *start =NULL;
		ListNode *pNext =NULL;
		unsigned int length = 1;
		while(p){
		  length++;
		  p = p->next;
		}
        if(length<k) return NULL;
        unsigned int count = 1;
        while(p!=NULL)
        {   
            pNext = p->next;
            if (count == k) 
            {
                start = pre == NULL ? head : pre->next;
                head = pre == NULL ? p : head;
                resign(pre, start, p, pNext);
                pre = start;
                count = 0;
            }
            count++;
            p = pNext;
        }
        return head;
    }
public:
    int  resign(ListNode* left, ListNode*  start, ListNode*  end,
            ListNode*  right)
    {
       ListNode* pre = start;
       ListNode* cur = start->next;
       ListNode* pNext = NULL;
       while(cur != right)
       {
           pNext = cur->next;
           cur->next = pre;
           pre = cur;
           cur = pNext;
       }
       if(left != NULL)
       {
           left->next = end;
       }
        start->next = right;
        return 0;
    }
};