 //LEETCODE
 //Check whether LinkedList has cycle or not
 
 bool hasCycle(ListNode *head) {
        ListNode * slow, *fast;
        slow=head;
        fast=head;
        bool firstTime=true;
        while(fast!=NULL && fast->next!=NULL )
        {
            if(slow==fast && !firstTime)
                return true;
            else
            {
            firstTime=false;
            slow=slow->next;
            fast=fast->next->next;
            }
        }
        return false;
    }
