class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //character
        std::unordered_set<char> unique;
        int max{};
        int index{};
        for (int i{}; i < s.size(); i++) {
            while (unique.contains(s[i])) {
                unique.erase(s[index]);
                index++;
            }
                
            unique.insert(s[i]);

            if (unique.size() > max) max = unique.size();
        }

        return max;
    }
};
