class Solution {
public:
    unordered_map<int, unordered_set<int>> hmap_node;
    unordered_set<int> visited_n;
    bool validTree(int n, vector<vector<int>>& edges) {
        for (auto & eg : edges) {
            hmap_node[eg[0]].insert(eg[1]);
            hmap_node[eg[1]].insert(eg[0]);
        }
        visited_n.insert(0);
        while(!hmap_node[0].empty()) {
            int to_n = *(hmap_node[0].begin());
            if (!helper(0, to_n)) {
                return false;
            }
            hmap_node[0].erase(to_n);
        }
        if (visited_n.size() != n) {
            return false;
        }
        return true;
    }

    bool helper(int from_n, int this_n) {
        if (visited_n.count(this_n)) {
            return false;
        }
        visited_n.insert(this_n);
        hmap_node[this_n].erase(from_n);
        while(!hmap_node[this_n].empty()) {
            int to_n = *(hmap_node[this_n].begin());
            if (!helper(this_n, to_n)) {
                return false;
            }
            hmap_node[this_n].erase(to_n);
        }
        return true;
    }
};
