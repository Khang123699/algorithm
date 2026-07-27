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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* firstPointer = head;
        for (int step = 1; step < k; step++) {
            firstPointer = firstPointer->next;
        }
        ListNode* leftNode = firstPointer;
        ListNode* secondPointer = head;
        while (firstPointer->next != nullptr) {
            firstPointer = firstPointer->next;
            secondPointer = secondPointer->next;
        }
        ListNode* rightNode = secondPointer;
        int temporaryValue = leftNode->val;
        leftNode->val = rightNode->val;
        rightNode->val = temporaryValue;
        return head;
    }
};