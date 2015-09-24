class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> htable;
        int begin = 0;
        int count = 0;

        if (s.size() == 0 || words.size() == 0) return res;

        for (int i = 0; i < words.size(); i++)
            htable[words[i]]++;

        int wordSize = words[0].size();
        for (int b = 0; b < wordSize; b++) {
            unordered_map<string, int> ttable;
            count = 0;
            begin = b;
            for (int i = b; i <= (int)(s.size() - wordSize); i += wordSize) {
                string word = s.substr(i, wordSize);
                if (htable.find(word) == htable.end()) {
                    ttable.clear();
                    begin = i + wordSize;
                    count = 0;
                    continue;
                }
                count++;
                if (ttable.find(word) == ttable.end()) {
                    ttable[word]++;
                }
                else {
                    ttable[word]++;

                    if (ttable[word] > htable[word]){
                        int t;
                        for (t = begin; t < i; t += wordSize) {//remove until meet dumplicate
                            count--;
                            ttable[s.substr(t, wordSize)]--;
                            if (s.substr(t, wordSize) == word)
                                break;
                        }
                        if (t < i)
                            begin = t + wordSize;
                        else
                            begin = i;
                    }
                }

                if (count == words.size()) {
                    res.push_back(begin);
                    count = 0;
                    i = begin;
                    begin = begin + wordSize;
                    ttable.clear();
                }
            }
        }
        return res;
    }
};