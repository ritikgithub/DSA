//LEETCODE
//Merge two sorted linkedlist using recursion

 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head;
        if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        if(l1->val<=l2->val) {
           head  = new ListNode(l1->val);
               head->next = mergeTwoLists(l1->next,l2);
        }
        else {
            head  = new ListNode(l2->val);
               head->next = mergeTwoLists(l1,l2->next);
        }
      return head;
    }
