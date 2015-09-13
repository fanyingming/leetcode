class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_multiset<string> htable;
        unordered_multiset<string> ttable;
        
        if (s.size() == 0 || words.size() == 0) return res;
        
        for (int i = 0; i < words.size(); i++) {
            htable.insert(words[i]);
        }
        
        int wordSize = words[0].size();
        
        for (int i = 0; i < s.size(); i++) {
            if (s.size()-1-i+1 < wordSize*words.size()) break;//剪枝,剩余单词长度不够
            ttable.clear();
            for (int j = i; j < s.size(); j += wordSize) {
                string word;
                for (int k = 0; k < wordSize; k++)  word += s[j+k];
                unordered_multiset<string>::iterator it = htable.find(word);
                if (it == htable.end()) {//word not in dict.
                    break;
                } else {
                    if (ttable.count(word) < htable.count(word)) // dumplicate words
                        ttable.insert(word);
                    else
                        break;
                }
            }
            
            if (ttable.size() == htable.size())
                res.push_back(i);
        }
        return res;
    }
};