class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i{}; i < tokens.size(); i++) {
            string c = tokens[i];
            int top{}, bot{};

            if(c == "+") {
                top = st.top();
                st.pop();
                bot = st.top();
                st.pop();
                st.push(top+bot);
            } else if(c == "-") {
                top = st.top();
                st.pop();
                bot = st.top();
                st.pop();
                st.push(bot-top);
            } else if(c == "*") {
                top = st.top();
                st.pop();
                bot = st.top();
                st.pop();
                st.push(top*bot);
            } else if(c == "/") {
                top = st.top();
                st.pop();
                bot = st.top();
                st.pop();
                st.push(std::floor(bot/top));
            } else {
                st.push(std::stoi(c));
            }
        }
        return st.top();
    }
};
