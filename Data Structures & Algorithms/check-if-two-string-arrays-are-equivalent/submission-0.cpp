class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        //lets build the completed words then compare
        string str1{};
        string str2{};

        for (auto& str : word1) {
            str1 += str;
        }

        for (auto& str : word2) {
            str2 += str;
        }

        return (str1 == str2);
    }
};
