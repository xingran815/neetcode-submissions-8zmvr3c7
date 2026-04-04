class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // use a stack to store the rest time of each car fleets
        // time calculation = ((double)target-pos)/speed;
        // time should be double precision
        // if the time_front_car >= time_behind_car, the two cars will meet
        // would there be an issue to compare two doubles??
        // initialize the time of the first car in the stack
        // iterate the array
        //      while the current car's time >= last car fleet's time
        //          pop the last car in the stack
        //      push the current car's time in the stack
        // the size of the stack is the size of the car fleet
        int n = position.size();
        if (n == 1) return n;

        vector<pair<int, int>> pos_spd(n);
        for (int i = 0; i < n; ++i) {
            pos_spd[i] = pair<int, int>(position[i], speed[i]);
        }
        sort(pos_spd.begin(), pos_spd.end());
        stack<double> time;
        double time_c = ((double)target - pos_spd[0].first)/pos_spd[0].second;
        time.push(time_c);
        for (int i = 1; i < n; ++i) {
            double time_c = ((double)target - pos_spd[i].first)/pos_spd[i].second;
            while (true) {
                double time_l = time.top();
                if (time_c < time_l) {
                    break;
                }
                time.pop();
                if (time.empty()) {
                    break;
                }
            }
            time.push(time_c);
        }
        return time.size();

    }
};
