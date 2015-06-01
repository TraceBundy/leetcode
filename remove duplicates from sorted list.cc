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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode *h = head;
        ListNode *l = head;
        while (h){
            l = h->next;
            while (l && l->val == h->val) l = l->next;
            h->next = l;
            h = l;
        }
        return head;
    }
};