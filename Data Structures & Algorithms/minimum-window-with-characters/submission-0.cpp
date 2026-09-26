class Solution {
   public:
    string minWindow(string s, string t) {
        string shortest;
        if (t.size() > s.size()) return shortest;
        if (s.size() == 0) return shortest;

        // create frequency map of t
        std::unordered_map<char, int> need(26);

        for (auto c : t) {
            need[c] += 1;
        }

        int l{}, r{};
        int bestIndex{}, bestSize{INT_MAX};
        
        
        std::unordered_map<char, int> window(26);

        // keep increasing until window contains all characters in t
        while (r < s.size()) {
            while (!windowMatches(need, window) && r < s.size()) {
                window[s.at(r)] += 1;
                r++;
            }
            //now shrink the window until no longer valid, store the string
            while (windowMatches(need, window) && l < s.size()) {
                //store the string then shrink  
                if (r-l < bestSize) {
                    bestIndex = l;
                    bestSize = r-l;
                }

                window[s.at(l)] -= 1;
                l++;
            }
        }
        
        if (bestSize == INT_MAX) return shortest;
        //build best string
        for (int i{}; i < bestSize; i++) {
            shortest += s[bestIndex];
            bestIndex++;
        }

        return shortest;
    }

    bool windowMatches(std::unordered_map<char, int>& need, std::unordered_map<char, int>& window) {
        for (auto& [c, count] : need) {
            if (!window.contains(c) || window.at(c) < need.at(c)) return false;
        }

        return true;
    }
};
