class Solution {
public:

    // Merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(left != NULL && right != NULL) {

            if(left->val < right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        // Remaining nodes
        if(left != NULL) {
            temp->next = left;
        }
        else {
            temp->next = right;
        }

        return dummy->next;
    }


    ListNode* sortList(ListNode* head) {

        // Base case
        if(head == NULL || head->next == NULL) {
            return head;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Divide into two lists
        ListNode* right = slow->next;
        slow->next = NULL;

        // Recursion
        ListNode* left = sortList(head);
        right = sortList(right);

        // Merge
        return merge(left, right);
    }
};