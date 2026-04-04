class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // initialize result with 0s.
        // loop through tempratures
        // check the temprature with the 0 - (i-1)th result
        // when result != 0, skip
        // when result == 0, compare the ith temprature with the temprature
        // in the past
        // if the ith temprature is higher, change the result
        vector<int> result (temperatures.size());
        for (int i = 0; i < temperatures.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (result[j] != 0) {
                    continue;
                } else if (temperatures[i] > temperatures[j]) {
                    result[j] = i-j;
                }
                cout << "i: " << i << ", j: " << j << ", result: " << result[j] << endl;
            }
        }
        
        return result;
    }
};
