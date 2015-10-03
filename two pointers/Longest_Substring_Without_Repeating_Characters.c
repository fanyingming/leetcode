class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> htable;
        int i, begin = 0;
        int max_length = 1;
        
        if (s.size() == 0)  return 0;
        htable.insert(s[0]);
        for (i = 1; i < s.size(); i++) {
            unordered_set<char>::const_iterator it = htable.find(s[i]);
            if (it == htable.end()) { // no dumplicate.
                max_length = max(max_length, i-begin+1);
                htable.insert(s[i]);
            } else {
                for (int j = begin; j < i; j++) {
                    if (s[j] == *it) {
                        begin = j+1;
                        break;
                    } else {
                        htable.erase(s[j]);
                    }
                }//for
            }//if
        }
        
        return max_length;
    }
};