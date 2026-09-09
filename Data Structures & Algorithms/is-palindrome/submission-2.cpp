class Solution {
   public:
    bool isPalindrome(string s) {
        int left{}, right = s.size() - 1;

        while (left <= right) {
            // ignore all except alphanumeric
            while (left < right && !((s[left] >= '0' && s[left] <= '9') 
                   || (s[left] >= 'a' && s[left] <= 'z') 
                   || (s[left] >= 'A' && s[left] <= 'Z'))) {
                left++;
            }
            while (right > left && !((s[right] >= '0' && s[right] <= '9') 
                    || (s[right] >= 'a' && s[right] <= 'z') 
                    || (s[right] >= 'A' && s[right] <= 'Z'))) {
                right--;
            }
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
