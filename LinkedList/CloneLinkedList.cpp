 //CLONE A LINKED LIST
 
 
 //Method 1-  Space- O(N), Time- O(N)
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
    
    
    //METHOD -2 Space-O(1) Time-O(N)
        Node* copyRandomList(Node* head) {
        Node *ptr,*temp,*ans;
        ptr = head;
        while(ptr!=NULL) {
            temp = new Node(ptr->val);
            temp->next = ptr->next;
            ptr->next = temp;
            ptr = ptr->next->next;
        }
        ptr = head;
        while(ptr!=NULL) {
            ptr->next->random = ptr->random ? ptr->random->next : NULL;
            ptr=ptr->next->next;
        }
       
        ans = head ? head->next : NULL;
         ptr = head;
        while(ptr!=NULL) {
            temp = ptr->next;
            ptr->next = ptr->next->next;
            if(temp->next)
               temp->next = temp->next->next;
            
            ptr=ptr->next;
        }
        return ans;
    }
