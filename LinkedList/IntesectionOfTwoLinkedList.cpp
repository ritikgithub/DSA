 //LEETCODE
 //Intersection point of two linked list
 
 
 //Method 1
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA=0,countB=0; 
        int i;
        ListNode *ptr1 ,*ptr2;
        ptr1=headA;ptr2=headB;
        while(ptr1!=NULL){
            countA++;
            ptr1=ptr1->next;
        }
        while(ptr2!=NULL){
            countB++;
            ptr2=ptr2->next;
        }
        int diff = abs(countA-countB);
        if(countA>=countB) {
            for(i=1;i<=diff;i++)
                headA=headA->next;
        }
        else {
                 for(i=1;i<=diff;i++)
                headB=headB->next;
        }
        while(headA!=headB && headA!=NULL && headB!=NULL) {
            headA = headA->next;
            headB = headB->next;
        }
        if(headA==NULL)
            return NULL;
        return headA;
    }
    
    
    
    //Method 2
    
    class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA, *ptr2 = headB;
        while(ptr1!=NULL && ptr2!=NULL)
        {
            ptr1 =ptr1->next;
            ptr2 = ptr2->next;
        }
        if(ptr1==NULL) {
            ptr1 = headB;
            while(ptr2!=NULL) {
                ptr1= ptr1->next;
                ptr2 = ptr2->next;
            }
            ptr2 = headA;
        }
        else {
            ptr2 = headA;
            while(ptr1!=NULL) {
                ptr1 = ptr1->next;
                ptr2=ptr2->next;
            }
            ptr1 = headB;
        }
        while(ptr1!=ptr2 && ptr1!=NULL) {
            ptr1= ptr1->next;
            ptr2= ptr2->next;
        }
    
        return ptr1;
    }
};


//strive way of writing method 2

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA, *ptr2 = headB;
       while(ptr1!=ptr2) {
           ptr1 = ptr1==NULL ? headB : ptr1->next;
           ptr2 = ptr2==NULL ? headA : ptr2->next;
       }
        return ptr1;
    }
};
