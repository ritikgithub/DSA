 //LEETCODE
 //Find the starting node of loop of linkedlist.
 
 ListNode *detectCycle(ListNode *head) {
        ListNode *slow,*fast;
        slow = head;
        fast = head;
        bool firstTime = true;
        while(fast && fast->next && (slow!=fast || firstTime)) {
            firstTime = false;
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast==NULL || fast->next==NULL)
            return NULL;
        
        fast = head;
        while(slow!=fast) {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
    }
