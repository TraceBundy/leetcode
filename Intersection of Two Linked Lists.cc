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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = listLength(headA);
        int lenB = listLength(headB);
        if (lenA > lenB){
            int i = 0;
            int x = lenA - lenB;
            while (i < x){
                headA = headA->next;
                ++i;
            }
        }
        if (lenA < lenB){
            int i = 0;
            int x = lenB - lenA;
            while (i < x){
                headB = headB->next;
                ++i;
            }
        }
        while (headA && headB){
            if (headA == headB){
                return headA;
            } else{
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }
    int listLength(ListNode *head){
        int i = 0;
        while (head) {
            head = head->next;
            ++i;
        }
        return i;
    }
};