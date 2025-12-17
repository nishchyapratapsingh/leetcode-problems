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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head -> next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* oddHead = odd;
        ListNode* evenHead = even;
        ListNode* oddTail = oddHead;
        ListNode* evenTail = evenHead;
        while (even && even -> next) {
            odd = odd -> next -> next;
            even = even -> next -> next;
            oddTail -> next = odd;
            evenTail -> next = even;
            oddTail = oddTail -> next;
            evenTail = evenTail -> next;
        }
        oddTail -> next = evenHead;
        return oddHead;
    }
};