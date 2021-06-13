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
    vector<int> reversePrint(ListNode* head) {
        if(head == NULL) return vector<int>(0);
        vector<int> ans;
        stack<int> store;
        while(head){
            store.push(head->val);
            head = head->next;
        }
        while(!store.empty()){
            ans.push_back(store.top());
            store.pop();
        }
        return ans;
    }
};
