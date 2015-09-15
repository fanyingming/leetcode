class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> rl;
		unordered_map<string, vector<string>> htable;
		for (int i = 0; i < strs.size(); i++) {
			string str = strs.at(i);
			string str_sorted = str;
			sort(str_sorted.begin(), str_sorted.end());

			unordered_map<string, vector<string>>::iterator it = htable.find(str_sorted);

			if (it == htable.end()) {
				htable[str_sorted].push_back(str);
			} else {
				vector<string>::iterator vit = it->second.begin();
				for (; vit != it->second.end(); vit++) {
					int k;
					int b_insert = 0;
					for (k = 0; k < str.size(); k++) {
						char c = str.at(k);
						if (c < vit->at(k)) {
							b_insert = 1;
							break;
						} else if (c > vit->at(k)) {
							b_insert = 0;
							break;
						}
					}
					if (k < str.size() && b_insert) {
						it->second.insert(vit, str);
						break;
					}
				}
				if (vit == it->second.end())
					htable[str_sorted].push_back(str);
			}
		}

		for (unordered_map<string, vector<string>>::iterator it = htable.begin(); it != htable.end(); it++)
			rl.push_back(it->second);
		return rl;
	}
};
