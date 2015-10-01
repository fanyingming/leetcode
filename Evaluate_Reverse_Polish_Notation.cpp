class Solution {
public:
    stack<int> sta;
    bool isNum(string str) {
        if (str.size() > 1)
            return true;
        if (str[0] >= '0' && str[0] <= '9')
            return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        int a, b, i;
        string s;
        for (i = 0; i < tokens.size(); i++) {
            s = tokens[i];
            
            if (isNum(s)){
                int num = 0;
                int sig = 1;
                int begin = 0;
                if (s[0] == '+') {
                    sig = 1;
                    begin = 1;
                } else if (s[0] == '-') {
                    sig = -1;
                    begin = 1;
                }
                
                for (int j = begin; j < s.size(); j++)
                    num = num*10 + s[j] - '0';

                sta.push(num*sig);
            } else {
                if (s.size() != 1) {
                    //assert(0);
                    break;
                }
                if (sta.size() < 2) {
                    //assert(0);
                    break;
                }
                //notice devide zero.
                b = sta.top();
                sta.pop();
                a = sta.top();
                sta.pop();
                switch (s[0]) {
                    case '+': a = a+b; break;
                    case '-': a = a-b; break;
                    case '*': a = a*b; break;
                    case '/': a = a/b; break;
                    default : break;//assert(0);
                }
                sta.push(a);
            }
        }
        if (s.size() != 1) {
        //    assert(0);
        }
        a = sta.top();
        return a;
    }
};