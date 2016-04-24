#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
有环时，当快指针和慢指针相遇时，让快指针等于头节点，
一次遍历一个,慢指针一次遍历一个，在进入环的第一个节点再次相遇
*/
class ChkLoop {
public:
    int chkLoop(ListNode* head, int adjust) {
        // write code here
        if(head==NULL || head->next==NULL)return -1;
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow!= NULL && fast != NULL && fast->next != NULL)
        {
          
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                fast = head;
                break;
            }
        }
        if(fast == head)
        {
            while(fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast->val;
            
        }
        return -1;
    }
};