/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(temp->val);
            Node* nextNode = temp->next;
            temp->next = newNode;
            newNode->next = nextNode;
            temp = temp->next->next;
        }
        temp = head;
        while (temp) {
            Node* copy = temp->next;
            if (temp->random) copy->random = temp->random->next;
            temp = temp->next->next;
        }
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        temp = head;
        while (temp) {
            tail->next = temp->next;
            tail = tail->next;
            temp->next = tail->next;
            temp = temp->next;
        }
        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};