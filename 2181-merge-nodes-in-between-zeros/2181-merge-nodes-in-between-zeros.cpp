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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> merged;

        ListNode* temp = head;
        int sum = 0;
        while (temp) {
            if (temp -> val == 0 && sum != 0) {
                merged.push_back(sum);
                sum = 0;
            }
            else {
                sum += temp -> val;
            }
            temp = temp->next; 
        }

        if (merged.empty()) return nullptr;

        ListNode* newHead = new ListNode(merged[0]);
        ListNode* tail = newHead;

        for (int i = 1; i < merged.size(); i++) {
            ListNode* newNode = new ListNode(merged[i]);
            tail -> next = newNode;
            tail = tail -> next;
        }

        return newHead;
    }
};