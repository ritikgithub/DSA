 //LEETCODE
 //Find Middle Element of LinkedList, in case of 2 middle elemenent return the second one
 
 ListNode* middleNode(ListNode* head) {
        ListNode *slow,*fast;
        slow = head;
        fast = head;
        while(fast!=NULL && fast->next!=NULL) {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
