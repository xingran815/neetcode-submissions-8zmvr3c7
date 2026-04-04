/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = l1 + l2
        // check if current digit sum needs to increment to the next higher digit
        // if so change it to 1, otherwise 0

        ListNode *p1, *p2;
        ListNode *p_last;
        p1 = l1;
        p2 = l2;
        int inc = 0;
        while (p1 || p2) {
            if (p1 && p2) {
                int digit = p1->val + p2->val + inc;
                p1->val = digit % 10;
                inc = digit / 10;
    
                p_last = p1;
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1) {
                if (inc == 0) {
                    break;
                }
                int digit = p1->val + inc;
                p1->val = digit % 10;
                inc = digit / 10;
    
                p_last = p1;
                p1 = p1->next;

            } else if (p2) {
                p_last->next = p2;
                p1 = p2;
                p2 = nullptr;
            }
        }
        if (inc) {
            ListNode* l = new ListNode(inc);
            p_last->next = l;
        }

        return l1;
        
    }
};
