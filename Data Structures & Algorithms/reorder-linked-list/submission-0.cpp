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
    void reorderList(ListNode* head) {
        // two loops, use queue and stack
        // in the first loop, fill the queue and the stack,
        // and the number of nodes
        // in the second loop, iterate over the number
        // when the number is even fill the stack
        // when               odd, fill the queue
        queue<ListNode*> q;
        stack<ListNode*> s;
        ListNode* p = head;
        int num = 0;
        while (p) {
            q.push(p);
            s.push(p);
            num++;
            p = p->next;
        }

        p = head;
        q.pop();
        cout << "num: " << num << endl;
        for (int i = 2; i <= num; ++i) {
            if (i%2 == 0) {
                p->next = s.top();
                p = p->next;
                s.pop();
            } else {
                p->next = q.front();
                p = p->next;
                q.pop();
            }
            cout << p->val << endl;
        }
        p->next = nullptr;
    }
};
