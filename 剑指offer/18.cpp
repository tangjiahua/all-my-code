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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *p = head, *q = head->next;
        if(head && head->val == val){
            head = head->next;
            return head;
        }
        while(q){
            if(q->val == val){
                  p->next = q->next;
                  break;
            }
            p = p->next;
            q = q->next;
        }
        return head;
    }
};
