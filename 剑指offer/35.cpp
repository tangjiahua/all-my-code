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
        if(head == NULL) return head;
        Node *p = head;
        unordered_map<Node*, Node*> map;
        while(p != NULL){
            map[p] = new Node{p->val};
            p = p->next;
        }
        p = head;
        while(p != NULL){
            map[p]->next = map[p->next];
            map[p]->random = map[p->random];
            p = p->next;
        }
        return map[head];
    }
};
