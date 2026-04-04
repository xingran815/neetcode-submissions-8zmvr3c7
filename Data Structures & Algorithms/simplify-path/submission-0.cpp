class Solution {
public:
    string simplifyPath(string path) {
        // use a queue<string> to track the path
        // loop over each char from the second element in the path
        // add each char to dir_file_name until encountering '/'
        // or when i = size - 1, and dir_file_name isn't empty
        //  compare dir_file_name against '.' '..'
        //      if dir_file_name is empty: skip
        //      '.': clear dir_file_name;
        //      '..': pop_back the queue, clear dir_file_name;
        //      else: push_back dir_file_name to the queue, clear dir_file_name
        string dir_file_name;
        string ans_path = "/";
        vector<string> path_q;

        cout << dir_file_name.size() << endl;
        dir_file_name = "xxxxx";
        cout << dir_file_name.size() << endl;
        dir_file_name = "";
        cout << dir_file_name.size() << endl;
        cout << dir_file_name.empty() << endl;


        for (int i = 1; i<path.size(); ++i) {
            if (i == path.size()-1 || path[i] == '/') {
                if (path[i] != '/') {
                    dir_file_name += path[i];
                }
                if (dir_file_name.empty()) {
                    continue;
                }
                if (dir_file_name == ".") {
                    // do nothing
                } else if (dir_file_name == "..") {
                    if (path_q.size() != 0) {
                        path_q.pop_back();
                    }
                } else {
                    path_q.push_back(dir_file_name);
                }
                dir_file_name = "";
            } else {
                dir_file_name += path[i];
            }
            

        }
        
        for (int i = 0; i<path_q.size(); ++i) {
            ans_path += path_q[i];
            if (i != path_q.size()-1) {
                ans_path += '/';
            }
        }
        return ans_path;
        
        
    }
};