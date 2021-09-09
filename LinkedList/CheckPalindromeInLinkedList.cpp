 //LEETCODE
 //Check whether palindrome is present or not
 
 bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast,*middle, *rev,*first, *second, *temp, *start;
        slow= head; fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        middle = slow;
        first = NULL;
        second = middle;
        while(second!=NULL)
        {
            temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }
        rev = first;
        start= head;
        while(rev!=NULL) {
            if(start->val != rev->val)
                return false;
            start = start->next;
            rev = rev->next;
        }
        return true;
    }
