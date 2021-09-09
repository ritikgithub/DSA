//GFG
//Flatten a linkedList

Node* mergeTwoLinkedList(Node *head1, Node *head2) {
    Node *head = new Node(0);
    Node *ptr = head;
    
    while(head1 && head2) {
        if(head1->data <= head2->data) {
            ptr->bottom = head1;
            head1= head1->bottom;
        }
        else {
             ptr->bottom = head2;
            head2= head2->bottom;
        }
        ptr = ptr->bottom;
    }
    if(head1==NULL) 
        ptr->bottom = head2;
    else
        ptr->bottom = head1;
        
    return head->bottom;
    
}


/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
    if(root->next==NULL)
        return root;
    Node *ptr1 =  mergeTwoLinkedList(root, root->next);
   Node *ptr2 =  root->next->next;
   while(ptr2) {
      ptr1 = mergeTwoLinkedList(ptr1, ptr2);
       ptr2= ptr2->next;
   }
   ptr1->next = NULL;
   return ptr1;
}


