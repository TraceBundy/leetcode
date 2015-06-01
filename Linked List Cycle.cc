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
        if (!head) return false;
        ListNode *slow = head;
        ListNode *fast = head;
        if (fast->next) {
            fast = fast->next->next;
            if (!fast) return false;
        }
        else return false;
        
        while (fast != slow){
            if (slow->next) slow = slow->next;
            else return false;
            if (fast->next){
                fast = fast->next->next;
                if (!fast) return false;
            } else {
                return false;
            }
        }
        return true;
    }
};