class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix{""};

        //the maximum prefix size is the minimum str size
        int minSize{};
        for (string& str : strs) {
            if (str.size() > minSize) minSize = str.size();
        }
        
        for (int i{}; i < minSize; i++) {
            bool valid{1};
            char c = strs[0][prefix.size()];
            for (string& str : strs) {
                if (str[prefix.size()] != c) valid = 0;
            }
            if (!valid) return prefix;
            if (valid) prefix += c;

        }

        return prefix;
    }
};