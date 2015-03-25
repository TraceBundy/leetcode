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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL) return NULL;
        ListNode *cur = head, *pre, *end = head;
        for (int i = 0; i < n-1; ++i){
            end = end->next;
        }
        while (end->next != NULL){
            pre = cur;
            cur = cur->next;
            end = end->next;
        }
        if (head == cur) {
            head = cur->next;
        }
        else {
            pre->next = cur->next;
        }
        delete(cur);
        return head;
    }
};