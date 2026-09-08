class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::unordered_map<char, int> sfreq;
        for (char c : s) {
            sfreq[c]+= 1;
        }

        std::unordered_map<char, int> tfreq;
        for (char c : t) {
            tfreq[c]+= 1;
        }

        return sfreq == tfreq;

    }
};
