  //LEETCODE
  //rotate a linkedList
  
    ListNode* rotateRight(ListNode* head, int k) {
       if(head==0 || k==0)
            return head;
        
        ListNode *ptr,*temp;
        int len = 1;
        ptr = head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            len++;
        }
        
        k = k%len;
        ptr->next = head;
        ptr = head;
        for(int i=1;i<=len-k-1;i++)
            ptr = ptr->next;
        head = ptr->next;
        ptr->next= NULL;
        return head;
        
    }
