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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return {-1, -1};
        }
        int firstCriticalIndex = -1;
        int previousCriticalIndex = -1;
        int minimumDistance = INT_MAX;
        ListNode* previousNode = head;
        ListNode* currentNode = head->next;
        int currentIndex = 1;
        while (currentNode->next != nullptr) {
            ListNode* nextNode = currentNode->next;
            bool isLocalMaxima = (currentNode->val > previousNode->val) && (currentNode->val > nextNode->val);
            bool isLocalMinima = (currentNode->val < previousNode->val) && (currentNode->val < nextNode->val);
            if (isLocalMaxima || isLocalMinima) {
                if (firstCriticalIndex == -1) {
                    firstCriticalIndex = currentIndex;
                } else {
                    int currentDistance = currentIndex - previousCriticalIndex;
                    if (currentDistance < minimumDistance) {
                        minimumDistance = currentDistance;
                    }
                }
                previousCriticalIndex = currentIndex;
            }
            previousNode = currentNode;
            currentNode = nextNode;
            currentIndex++;
        }
        if (minimumDistance == INT_MAX) {
            return {-1, -1};
        }
        int maximumDistance = previousCriticalIndex - firstCriticalIndex;
        return {minimumDistance, maximumDistance};
    }
};