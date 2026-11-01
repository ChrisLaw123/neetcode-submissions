class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res{};
        int p1{};
        int p2{};
        bool alternate{1};
        while (p1 < word1.size() || p2 < word2.size()) {
            if (p1 == word1.size()) {
                res += word2[p2];
                p2++;
            } else if (p2 == word2.size()) {
                res += word1[p1];
                p1++;
            } else if (alternate) {
                res += word1[p1];
                p1++;
                alternate = false;
            } else {
                res += word2[p2];
                p2++;
                alternate = true;
            }
        }
        return res;
    }
};