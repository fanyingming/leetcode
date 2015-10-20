class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> htable;
        int index = 0;
        int maxLength = 1;
        int i;

        if (s.size() == 0)  return 0;
        htable.insert(s[0]);
        for (i = 1; i < s.size(); i++) {
            if (htable.find(s[i]) == htable.end()) {
                htable.insert(s[i]);
                maxLength = max(maxLength, i-index+1);
            } else {
                for (int j = index; j < i; j++) {
                    if (s[j] == s[i]) {
                        index = j+1;
                        break;
                    }
                    htable.erase(s[j]);
                }
            }
        }
        return maxLength;
    }
};