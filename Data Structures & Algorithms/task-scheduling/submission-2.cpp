class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // use max_heap and queue(fifo) to solve this problem
        // max_heap shows the frequency of the tasks, queue the order
        if (tasks.empty()) {
            // no tasks to be executed
            return 0;
        }
        vector<int> freq(26,0);
        for (char c : tasks) {
            freq[c-'A']++;
        }
        priority_queue<pair<int, char>> tasks_pq;
        // task_waiting<time_ready, <freq, letter>>
        queue<pair<int,pair<int,char>>> task_waiting_q;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                tasks_pq.push({freq[i], static_cast<char>(i+'A')});
            }
        }

        int time = 0;
        while (!task_waiting_q.empty() || !tasks_pq.empty()) {
            // execute a task from the executing queue
            if (!tasks_pq.empty()) {
                auto cur_task = tasks_pq.top();
                cout << cur_task.second << endl;
                tasks_pq.pop();
                // add cur_task to the waiting queue
                if (cur_task.first > 1) {
                    task_waiting_q.push({time+n, {cur_task.first-1, cur_task.second}});
                }
            } else {
                cout << "idle" << endl;
            }
            // add a waiting task to the executing queue
            if (!task_waiting_q.empty()) {
                auto task_waiting = task_waiting_q.front();
                if (task_waiting.first <= time) {
                    tasks_pq.push(task_waiting.second);
                    task_waiting_q.pop();
                }
            }
            time++;
        }
        return time;
    }
};
