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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode *fastNode = head->next, *slowNode = head;
        while(fastNode){
            if(fastNode->val == slowNode->val){
                return true;
            }
            if(fastNode->next == NULL) break;
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
        }
        return false;
    }
};
