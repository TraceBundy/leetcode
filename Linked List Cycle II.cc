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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        do {
            if (!slow || !fast) return NULL;
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
            else return NULL;
        }while(fast != slow);
        slow = head;
        while (slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};