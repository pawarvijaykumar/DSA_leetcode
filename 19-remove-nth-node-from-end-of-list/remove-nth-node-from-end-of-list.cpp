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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast pointer n steps
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers together
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the required node
        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;

        delete deleteNode;

        return dummy->next;
    }
};