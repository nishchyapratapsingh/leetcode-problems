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
        if (!head || k == 0) return head;
        ListNode* tail = head;
        int cnt = 1;
        while (tail->next) {
            tail = tail->next;
            cnt++;
        }
        k = k % cnt;
        cnt -= k;
        tail -> next = head;
        ListNode* prev = NULL;
        while (head && cnt--) {
            prev = head;
            head = head->next;
        }
        prev->next = NULL;
        return head;
    }
};