 //LEETCODE
 
 
 ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first, *second;
        first = head;
        second = head;
        if(head==NULL)
            return head;
        for(int i=1;i<=n;i++) {
            if(second==NULL)
                return head;
            second=second->next;
        }
        if(second==NULL) {
            head = head->next;
            return head;
        }
        while(second->next!=NULL)
        {
            second=second->next;
            first=first->next;
        }
        first->next = first->next->next;
        return head;
    }
