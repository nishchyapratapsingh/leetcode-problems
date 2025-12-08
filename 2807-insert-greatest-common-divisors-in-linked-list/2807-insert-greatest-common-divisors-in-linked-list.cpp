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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *dummy = head;
        while (dummy->next!=nullptr) {
            int a = dummy->val;
            int b = dummy->next->val;
            int gcdVal = gcd(a, b);

            ListNode *newNode = new ListNode(gcdVal);
            ListNode *temp = dummy->next;
            dummy->next = newNode;
            newNode->next = temp;
            dummy = dummy->next->next;
        }
        return head;
    }
};