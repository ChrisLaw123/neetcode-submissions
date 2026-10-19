class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp{}, tp{};

        //iterate until either pointer reaches the end. if 
        while (sp < s.size() && tp < t.size()) {
            if (s[sp] == t[tp]) {
                tp++;
                sp++;
            } else {
                tp++;
            }
        }

        if (sp == s.size()) return true;
        return false;
    }
};