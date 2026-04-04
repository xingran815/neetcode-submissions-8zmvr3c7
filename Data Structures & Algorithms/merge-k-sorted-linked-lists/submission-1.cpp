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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // use a map<val, ListNode*>
        // add the first element of each linked list to the map
        // while the map is not empty,
        // take out the first element of the map, 
        // add the element(node) to the end of the merged list,
        // remove this element from the map
        // move the pointer to the next node
        // add the next node to the map (if not nullptr)

        // insert O(N*logN)
        // delete O(1)
        multimap<int, ListNode*> list_map;
        ListNode* p_list;
        for (auto l : lists) {
            list_map.emplace(l->val, l);
        }
        ListNode* dummy = new ListNode(0);
        p_list = dummy;
        while (!list_map.empty()) {
            auto p_front = list_map.begin();
            p_list->next = p_front->second;
            list_map.erase(p_front);
            p_list = p_list->next;
            if (p_list->next) {
                list_map.emplace(p_list->next->val, p_list->next);
            }
        }
        p_list->next = nullptr;
        p_list = dummy->next;
        delete dummy;
        return p_list;
    }
};
