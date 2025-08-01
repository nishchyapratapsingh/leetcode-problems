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
        unordered_map<ListNode*, int> freq;
        while (headA || headB) {
            if (headA) {
                freq[headA]++;
                if (freq[headA]>1){
                    return headA;
                }
                headA = headA->next;
            }
            if (headB) {
                freq[headB]++;
                if (freq[headB]>1){
                    return headB;
                }
                headB = headB->next;
            }
        }
        return nullptr;
    }
};