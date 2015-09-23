class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_multiset<string> htable;
        
        if (s.size() == 0 || words.size() == 0) return res;
        
        for (int i = 0; i < words.size(); i++) {
            htable.insert(words[i]);
        }
        
        int wordSize = words[0].size();
        
        for (int i = 0; i < (int)(s.size() - wordSize*words.size()); i++) {
            unordered_multiset<string> ttable;
            for (int j = i; j < s.size(); j += wordSize) {
                string word = s.substr(j, wordSize);
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