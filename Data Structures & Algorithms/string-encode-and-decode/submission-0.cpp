class Solution {
public:

    string encode(vector<string>& strs) {
        // the encoded string has the following header
        // "number of strs,length of the 1st string,length of the 2nd string"
        // header is stored in a vector<int> (strs.size()+1)
        // two spaces after the header is the first string
        string sheader;
        string content;
        // the number of strs
        sheader += to_string(strs.size());
        for (int i = 0; i < strs.size(); ++i) {
            sheader += ' ';
            sheader += to_string(strs[i].size());
            content += strs[i];
        }
        sheader += ',' + content;
        cout << sheader << endl;
        return sheader;
    }

    vector<string> decode(string s) {
        // first read in the size of the strs
        // initialize the size of the strs
        // 2 loops
        // 1 loop: fill in the header vector, the total size and
        // length of each string
        // 2 loop: according to the info of the first loop, fill the vector<str>

        stringstream ss(s);
        int size;
        ss >> size;
        vector<int> header(size+1);
        vector<string> ans(size);

        header[0] = size;
        cout << size << endl;
        for (int i = 0; i < header[0]; ++i) {
            ss >> header[i+1];
            cout << header[i+1] << endl;
        }
        auto pos = s.find(',')+1;
        for (int i = 0; i < header[0]; ++i) {
            cout << s.substr(pos, header[i+1]) << endl;
            ans[i] = s.substr(pos, header[i+1]);
            pos += header[i+1];
        }
        return ans;

    }
};
