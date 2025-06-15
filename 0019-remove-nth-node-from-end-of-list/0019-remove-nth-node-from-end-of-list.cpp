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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Two pointer
        ListNode* dummy = new ListNode(); //allows us to delete head like a normal node
        dummy->next=head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        //move fast n+1 ahead so that slow is 1 node behind the node to delete
        for (int i=0; i<=n; i++) {
            if (!fast) return NULL;
            fast=fast->next;
        }

        while(fast) {
            fast=fast->next;
            slow=slow->next;
        }

        ListNode* toDel=slow->next;
        slow->next=slow->next->next;
        delete toDel;

        return dummy->next;
    }
};