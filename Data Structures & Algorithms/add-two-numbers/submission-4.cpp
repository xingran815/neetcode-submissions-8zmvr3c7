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
        // create a new List for the result
        // loop while p1 or p2 or inc==1
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        ListNode *p1 = l1, *p2 = l2;
        int inc = 0;
        
        while (p1 || p2 || inc) {
            int v1 = (p1==nullptr) ? 0 : p1->val;
            int v2 = (p2==nullptr) ? 0 : p2->val;

            int res = (v1+v2+inc)%10;
            inc = (v1+v2+inc)/10;
            ListNode* p_new = new ListNode(res);
            p->next = p_new;
            p = p_new;
            if (p1) {
                p1 = p1->next;
            }
            if (p2) {
                p2 = p2->next;
            }
        }

        p = dummy->next;
        delete dummy;
        return p;
        
    }
};
