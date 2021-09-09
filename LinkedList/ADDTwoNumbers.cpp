//LEETCODE
//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.


//Space - O(1)
//Time - O(M+N)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = l1, *prev=NULL;
        int carry = 0,value;
        
        while(l1!=NULL && l2!=NULL) {
            value  = l1->val + l2->val + carry;
            l1->val = value%10;
            carry = value/10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1==NULL && l2==NULL) {
            if(carry == 1) {
                prev->next = new ListNode(1);
            }
        }
        else if(l2==NULL) {
            while(l1!=NULL) {
                value = l1->val+carry;
                l1->val = value%10;
                carry = value/10;
                prev = l1;
                l1 = l1->next;
            }
            if(carry == 1) {
                prev->next = new ListNode(1);
            }
        }
        else {
            prev->next = l2;
            while(l2!=NULL) {
                 value = l2->val+carry;
                 l2->val = value%10;
                 carry = value/10;
                prev = l2;
                l2 = l2->next;
            }
              if(carry == 1) {
                prev->next = new ListNode(1);
            }
        }
        return head;
    }
};


//Striver Solution
//main Thing to learn is create dummy node so you dont have to take first case differently and also how carry case is covered
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *ptr = dummy;
        int sum=0,carry=0;
        while(l1!=NULL || l2!=NULL || carry==1) {
            sum=0;
            if(l1!=NULL) {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL) {
                sum+=l2->val;
                l2 = l2->next;
            }
            sum+=carry;
            ptr->next = new ListNode(sum%10);
            carry = sum/10;
            ptr = ptr->next;
        }
        return dummy->next;
    }
};
