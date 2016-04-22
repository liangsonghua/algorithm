#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        // write code here
       ListNode *slow = pHead;
       ListNode *fast = pHead;
      while(fast->next != NULL&&fast->next->next != NULL){
          slow = slow->next;//最后slow指向中间节点
          fast = fast->next->next;//最后fast指向最后一个节点
      }
      fast = slow->next;
      slow->next = NULL;
       //将右边节点逆转
       ListNode *tmp = NULL;
       while(fast!=NULL)
        {
            tmp = fast->next;
            fast->next = slow;
           //防止断链
            slow = fast;
           //fast = fast->next;
            fast = tmp;
       }
        tmp = slow;//保留最后一个节点
        //此时slow指向最后一个节点
       fast = pHead;
       while(tmp != NULL && fast != NULL){
           if(tmp->val != fast->val){
               return false;
           }
           tmp = tmp->next;
           fast = fast->next;
       }
       return true;
	}
};