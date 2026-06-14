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
private:
    ListNode* rev(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur) {
            ListNode* nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }

        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revHead = rev(slow);
        slow = head;
        int mx = INT_MIN;
        while (slow && revHead) {
            mx = max(mx, slow->val + revHead->val);
            revHead = revHead->next;
            slow = slow->next;
        }

        return mx;
    }
};