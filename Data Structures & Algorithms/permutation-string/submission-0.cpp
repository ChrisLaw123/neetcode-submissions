class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;

        std::unordered_map<char, int> s1freq (26);

        //get the character count and window size of s1 
        int windowSize = s1.size();
        for (auto c : s1) {
            s1freq[c] += 1;
        }

        //initialize sliding window of size windowSize
        std::deque<char> window;
        std::unordered_map<char, int> windowFreq (26);
        for (int i{}; i < windowSize; i++) {
            window.push_back(s2[i]);
            windowFreq[s2[i]] += 1;
        }

        //slide window until we reach the end of s2
        int left{};
        //initialize at the next character
        for (int i = windowSize; i < s2.size(); i++) {
            if (s1freq == windowFreq) return true;

            window.push_back(s2[i]);
            windowFreq[s2[i]] += 1;
            windowFreq[s2[left]] -= 1;
            if (windowFreq[s2[left]] == 0) windowFreq.erase(s2[left]);
            window.pop_front();
            left++;
        }
        return s1freq == windowFreq;
    }
};
