//LEETCODE
//Merge two soreted Linked List (Iterative Method)


//INplace -- space - O(1)
 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head = NULL, *ptr = NULL;
        if(l1==NULL)
            return l2;
        else if(l2==NULL)   
            return l1;
        
       while(l1!=NULL && l2!=NULL) {
           if(l1->val<=l2->val) {
               if(head==NULL) {
                   head = ptr = new ListNode(l1->val);
               }
               else {
                   ptr->next = l1;
                   ptr= ptr->next;
               }
               l1 = l1->next;
           }
           else {
               if(head==NULL) {
                   head = ptr = new ListNode(l2->val);
               }
               else {
                   ptr->next = l2;
                  ptr= ptr->next;
               }
               l2 = l2->next;
           }
       }
        if(l1==NULL) {
            ptr->next = l2;
        }
        else 
            ptr->next = l1;
        
        return head;
    }
    
    
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
 
 //OUTPLACe, space- O(N)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head = NULL, *ptr = NULL;
        if(l1==NULL)
            return l2;
        else if(l2==NULL)   
            return l1;
        
       while(l1!=NULL && l2!=NULL) {
           if(l1->val<=l2->val) {
               if(head==NULL) {
                   head = ptr = new ListNode(l1->val);
               }
               else {
                  ptr->next = new ListNode(l1->val);
                    ptr=ptr->next;
               }
               l1 = l1->next;
           }
           else {
               if(head==NULL) {
                   head = ptr = new ListNode(l2->val);
               }
               else {
                  ptr->next = new ListNode(l2->val);
                   ptr=ptr->next;
               }
               l2 = l2->next;
           }
       }
       while(l2!=NULL) {
           ptr->next = new ListNode(l2->val);
           ptr = ptr->next;
           l2= l2->next;
       }
        
    while(l1!=NULL)    {
         ptr->next = new ListNode(l1->val);
           ptr = ptr->next;
           l1= l1->next;
    }
        
        return head;
    }
};
