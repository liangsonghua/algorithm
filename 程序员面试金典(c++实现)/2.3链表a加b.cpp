#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        // write code here
        ListNode *head = new ListNode(-1);
        ListNode *p = head;
        ListNode *pa = a;
        ListNode *pb = b;
        int c=0, sum ,val1,val2;//c为进位标记
        while(pa!=NULL||pb!=NULL||c!=0){
            val1 = (pa==NULL?0:pa->val);
            val2= (pb==NULL?0:pb->val);
            sum = val1+val2+c;
            c = sum/10;
            ListNode *node = new ListNode(sum%10);
            p->next = node;
            p = node;
            pa = (pa==NULL?NULL:pa->next);
            pb = (pb==NULL?NULL:pb->next);
        }
        return head->next;
    }
};