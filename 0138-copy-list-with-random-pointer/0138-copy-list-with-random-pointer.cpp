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
        unordered_map<Node*, Node*> map;
        Node* temp = head;

        while (temp) {
            Node* newNode = new Node(temp->val);
            map[temp] = newNode;
            temp = temp->next;
        }
        Node* newHead = map[head];
        temp = head;
        while (temp) {
            newHead->next = map[temp->next];
            newHead->random = map[temp->random];
            temp = temp->next;
            newHead = newHead->next;
        }
        return map[head];
    }
};