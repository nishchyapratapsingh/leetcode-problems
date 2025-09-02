class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; 
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* firstHalf = head;
        ListNode* secondHalf = slow->next;
        queue<int> leftHalf;
        stack<int> rightHalf;
        while (firstHalf != slow->next) {
            leftHalf.push(firstHalf->val);
            firstHalf = firstHalf->next;
        }
        while (secondHalf) {
            rightHalf.push(secondHalf->val);
            secondHalf = secondHalf->next;
        }
        while (!leftHalf.empty() && !rightHalf.empty()) {
            if (leftHalf.front() != rightHalf.top()) {
                return false;
            }
            leftHalf.pop();
            rightHalf.pop();
        }  
        return true;
    }
};
