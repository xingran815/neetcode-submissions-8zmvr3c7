class Solution {
    unordered_map<int, vector<int>> pre_hmap; // prerequisites are in vector<int>
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto pre: prerequisites) {
            pre_hmap[pre[0]].push_back(pre[1]);
        }
        unordered_set<int> pre_hset;
        for (int i = 0; i<numCourses;++i) {
            if (!helper(i, pre_hset))
                return false;
        }
        return true;
    }
    bool helper(int course, unordered_set<int> &pre_hset) {
        if (pre_hmap.count(course) == 0) {
            // not prerequisites
            return true;
        }
        if (pre_hset.count(course) != 0) {
            return false;
        }
        pre_hset.insert(course);
        auto cour_v = pre_hmap[course];
        for (auto c: cour_v) {
            if (!helper(c, pre_hset)) {
                return false;
            }
        }
        pre_hset.erase(course);
        pre_hmap.erase(course);
        return true;

    }
};
