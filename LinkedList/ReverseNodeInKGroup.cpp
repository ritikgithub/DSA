//LEETCODE
//Reverse node in k-group 
 
  pair<ListNode*,ListNode*> reverseToK(ListNode* head, int k) {
        ListNode *first, *second,*temp;
        first  = NULL;
        second = head;
        while(k--) {
            temp =second->next;
            second->next = first;
            first =  second;
            second = temp;
        }
        return {first,second};
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ptr, *prev, *dummy, *reverseNode, *nextNode;
        int count,m;
        ptr = head;
        pair<ListNode*,ListNode*>p;
        count=0;
        while(ptr!=NULL){
            count++;
            ptr=ptr->next;
        }
        m = count/k;
        dummy = new ListNode(0);
        prev = dummy;
        ptr  = head;
        while(m--) {
            p = reverseToK(ptr,k);
            reverseNode = p.first;
            nextNode = p.second;
            prev->next = reverseNode;
            prev = ptr;
            ptr = nextNode;
        }
        prev->next = ptr;
        return dummy->next;
    }
