class Solution {
public:
    void reverseString(vector<char>& s) {
        int l{}, r = s.size() - 1;

        while (l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};