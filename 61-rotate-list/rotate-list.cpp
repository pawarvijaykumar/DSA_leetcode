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
    ListNode* rotateRight(ListNode* head, int k) {

        // Step 1: Check empty list or single node
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // Step 2: Find length and tail
        ListNode* tail = head;
        int length = 1;

        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // Step 3: Optimize k
        k = k % length;

        if (k == 0) {
            return head;
        }

        // Step 4: Make circular linked list
        tail->next = head;

        // Step 5: Find new tail
        int steps = length - k;

        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // Step 6: Find new head and break circle
        ListNode* newHead = newTail->next;

        newTail->next = nullptr;

        return newHead;
    }
};
