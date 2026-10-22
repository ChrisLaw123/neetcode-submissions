class Solution {
public:
    int scoreOfString(string s) {
        int score{};
        char curr = s[0];
        for (int i{1}; i < s.size(); i++) {
            score += abs(curr - s[i]);
            curr = s[i];
        }
        return score;
    }
};