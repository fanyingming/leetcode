class Solution {
public:
    stack<int> sta;
    int max1(int a, int b) {
        return a > b ? a : b;
    }
    int longestValidParentheses(string s) {
        int max_len = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                sta.push(i);
            } else {
                if (sta.empty()) {
                    start = i+1;
                } else {
                    sta.pop();
                    //1. ))))((((())))   2.(((((((()))
                    max_len = sta.empty() ? max1(max_len, i-start+1) : max1(max_len, i - sta.top());
                }
            }
        }
        
        return max_len;
    }
};