#include"head.h"


  //Definition for singly-linked list.
  struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        //是否有环
        while(!slow && !fast->next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
            {
                
            }
        }
        return nullptr;
    }
};