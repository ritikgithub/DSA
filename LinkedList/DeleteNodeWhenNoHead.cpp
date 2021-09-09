//LEETCODE
//DELETE A Particular node but no head is given

void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        return;
    }
