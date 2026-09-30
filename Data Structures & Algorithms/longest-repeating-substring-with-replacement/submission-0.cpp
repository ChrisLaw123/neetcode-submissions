class Solution {
public:
    int characterReplacement(string s, int k) {
        //if the window is valid, expand, else shrink
        std::unordered_map<char, int> count;

        int maxSize{};
        int size{};

        int l{}, r{};
        while (r < s.size()) {
            count[s[r]] += 1;
            size++;
            r++;
            while (!valid(count, k)) {
                count[s[l]] -= 1;
                size--;
                l++;
            }
            if (size > maxSize) maxSize = size;
        }
        return maxSize;
    }

    bool valid(std::unordered_map<char, int>& count, int k) {
        //find most frequent character + k = total count
        int max{};
        int totalCount{};
        for (auto [character, num] : count) {
            if (num > max) max = num;
            totalCount += num;
        }

        if (max + k >= totalCount) return true;
        return false;
    }
};
