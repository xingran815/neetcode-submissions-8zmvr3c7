class Solution {
    unordered_set<int> cycle;
    unordered_set<int> visit;
    vector<int> output;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereq_map;
        // <course, all the prerequisites>
        for (const auto & course : prerequisites) {
            prereq_map[course[0]].push_back(course[1]);
        }
        for (int i = 0; i<numCourses; ++i) {
            if (helper(prereq_map, i) == false)
                return {};
        }
        return output;
    }
    // in a recursion
    // get all the prerequisites
    // loop over all the prerequisites
    // call the recursion until there is no prerequisites
    bool helper(unordered_map<int, vector<int>> &pre_map,
                int course
                ) {
        if (cycle.count(course)) {
            return false;
        }
        if (visit.count(course)) {
            return true;
        }
        cycle.insert(course);
        for (auto crs : pre_map[course]) {
            if (helper(pre_map, crs) == false) {
                return false;
            }
        }
        cycle.erase(course);
        visit.insert(course);
        output.push_back(course);
        return true;
    }

};
