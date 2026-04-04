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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // use a stack<ListNode*>
        // while list doesn't reach the end
        // fill the stack until it reaches k
        // when the stack is full, remember the next node, the first node
        //      p->next = stack.top()
        //      pop the stack till it is empty
        //      point the last node in the stack to the next node

        stack<ListNode*> st;
        ListNode* dummy = new ListNode(0);
        ListNode *p_begin, *p_end, *p;
        p_begin = dummy;
        p = head;
        while (p) {
            st.push(p);
            if (st.size() == k) {
                p_end = p->next;

                while(!st.empty()) {
                    p_begin->next = st.top();
                    st.pop();
                    p_begin = p_begin->next;
                }
                p_begin->next = p_end;
                p = p_end;
            } else {
                p = p->next;
            }
        }
        p = dummy->next;
        delete dummy;
        return p;
        
    }
};
