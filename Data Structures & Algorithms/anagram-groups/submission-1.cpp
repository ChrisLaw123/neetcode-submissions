class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::vector<int>, std::vector<std::string>> groups;
        vector<vector<string>> res;

        for (auto str : strs) {
            //build character count vector
            std::vector<int> key (26);
            for (auto c : str) {
                key[c - 'a'] += 1;
            }
            //insert into matching group, or create a new group
            if (!groups.contains(key)) {
                std::vector<std::string> x;
                x.push_back(str);
                groups.insert({key, x});
            } else {
                groups.at(key).push_back(str);
            }
        }

        //now we construct the groups of strings
        for (auto [key, strs] : groups) {
            vector<string> group;
            for (auto str : strs) {
                group.push_back(str);
            }
            res.push_back(group);
        }

        return res;
    }
};
