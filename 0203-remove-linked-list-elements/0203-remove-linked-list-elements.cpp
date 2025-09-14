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
    void removeNode(ListNode* &head, ListNode* node) {
        if (head==node) {
            head=head->next;
            delete node;
            return;
        }
        ListNode* nodeBeforeDel = head;
        while (nodeBeforeDel->next) {
            if (nodeBeforeDel->next==node) {
                nodeBeforeDel->next = node->next;
                delete node;
                return;
            }
            nodeBeforeDel = nodeBeforeDel->next;
        }
    }
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* node = head;
        while (node) {
            if (node->val == val) {
                ListNode* nextNode=node->next;
                removeNode(head, node);
                node = nextNode;
            }
            else
            node = node->next;
        }
        return head;
    }
};