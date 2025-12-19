/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tailA = headA;
        ListNode* tailB = headB;
        while (tailA != tailB) {
            if (tailA == tailB) {
                return tailA;
            }
            tailA = tailA == NULL ? headB : tailA->next;
            tailB = tailB == NULL ? headA : tailB->next;
        }
        return tailA;
    }
};