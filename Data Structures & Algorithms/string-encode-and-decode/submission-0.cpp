class Solution {
   public:
    string encode(vector<string>& strs) {
        std::string res;

        for (auto str : strs) {
            res += str;
            store.push_back(str.size());
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int totalIndex{};
        for (auto size : store) {
            string x;
    
            for (int i{totalIndex}; i < totalIndex + size; i++) {
                x+= s[i];
            }
            totalIndex += size;
           res.push_back(x);
        }

        return res;
    }

    // store the sizes of each word in the string to decode
    std::vector<int> store;
};
