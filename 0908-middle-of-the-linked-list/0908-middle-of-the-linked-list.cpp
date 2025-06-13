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
    ListNode* middleNode(ListNode* head) {
        int count = 1;
        ListNode* newnode = head;
        while (newnode->next!=NULL) {
            newnode=newnode->next;
            count++;
        }
        int temp = count/2;
        ListNode* newnode1 = head;
        while (temp){
            newnode1=newnode1->next;
            temp--;
        }
        return newnode1;
    }
};