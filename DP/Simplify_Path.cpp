/*
**这道题考虑的情况太多，如何能够有一种构造，使得分支判断尽量少。
*
*/
class Solution {
public:
    stack<string> sta;
    string simplifyPath(string path) {
        int begin = 0;
        int len = 0;
        string res;
        string word = "";
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (len > 0) {
                    word = path.substr(begin, len);
                    sta.push(word);
                }
                begin = i+1; len = 0; word = "";//init word memory
            } else if (path[i] == '.' && len == 0) {//start with '.'
                if (i+1 < path.size()) {
                    if (path[i+1] == '.') {//double "."
                        if (i+2 < path.size() && path[i+2] != '/') { //not "../"
                            begin = i;
                            len = 3;
                            i += 2;
                        } else {
                            if (sta.empty() == false) {
                                sta.pop();
                                begin = i+1; len = 0; word = ""; 
                            }
                        }
                    } else {//begin with "."
                        if (path[i+1] != '/') { //should link .x
                            begin = i; len = 2; i += 1;
                        }
                    }
                }
            } else {
                len++;
            } 
        }
        //end with word, not '/'
        if (len > 0) {
            word = path.substr(begin, len);
            sta.push(word);
        }
        if (sta.empty() == true)
            return "/";
        while (sta.empty() == false) {
            res.insert(0, "/" + sta.top());
            sta.pop();
        }
        return res;
    }
};