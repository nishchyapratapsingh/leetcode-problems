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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 0;
        while (temp) {
            temp = temp->next;
            n++;
        }
        temp = head;
        n = n/k;
        ListNode dummy;
        dummy.next = head;
        ListNode* before = &dummy;
        ListNode* groupTail = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(n--) {
            groupTail = curr;
            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr -> next = prev;
                prev = curr;
                curr = next;
            }
            before->next = prev;
            groupTail -> next = curr;
            before = groupTail;
        }
        return dummy.next;
    }
};