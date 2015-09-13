class Solution {
public:
    vector<string> rl;
    void generateCand(string s, int index, vector<string>& cand, vector<string>& ip) {
        int count = 0;
        for (int i = 0; i < ip.size(); i++)
            count += ip.at(i).size();
        if (count + 3*(4-ip.size()) < s.size())//剪枝，去掉一眼看去就不可能的情况。
            return;
            
        int num = 0;
        string num_str = "";
        for (int i = index; i < s.size(); i++) {
            int t = s[i] - '0';
            num = num*10 + t;
            num_str += s[i];
            
            if (num <= 255)
                cand.push_back(num_str);
            else
                break;
            
            if (num == 0)   return;//begin with 0
        }
    }
    void backTrace(string s, int index, vector<string>& ip) {
        if (index == s.size() && ip.size() == 4) {
            string str;
            for (int i = 0; i < ip.size(); i++) {
                str += ip.at(i);
                if (i <= 2 )    str += ".";
            }
            rl.push_back(str);
        } else {
            vector<string> cand;
            generateCand(s, index, cand, ip);
            for (int i = 0; i < cand.size(); i++) {
                ip.push_back(cand.at(i));
                backTrace(s, index+cand.at(i).size(), ip);
                ip.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ip;
        backTrace(s, 0, ip);
        return rl;
    }
};