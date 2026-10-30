class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        
        for (auto& operation : operations) {
            if (operation == "+") {
                int top = s.top();
                s.pop();
                int prev = s.top();
                s.push(top);
                s.push(prev+top);
            } else if (operation == "D") {
                s.push(s.top() * 2);
            } else if (operation == "C") {
                s.pop();
            } else {
                s.push(stoi(operation));
            }
        }

        int res{};
        while (!s.empty()) {
            res += s.top();
            s.pop();
        }
        return res;
    }
};