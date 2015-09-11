class Solution {
public:
	vector<string> rl;
	void generateCand(string digits, int index, vector<string>& cand) {
		char s = digits[index];
		cand.clear();
		switch (s) {
		case '2':
			cand.push_back("a"); cand.push_back("b"); cand.push_back("c"); break;
		case '3':
			cand.push_back("d"); cand.push_back("e"); cand.push_back("f"); break;
		case '4':
			cand.push_back("g"); cand.push_back("h"); cand.push_back("i"); break;
		case '5':
			cand.push_back("j"); cand.push_back("k"); cand.push_back("l"); break;
		case '6':
			cand.push_back("m"); cand.push_back("n"); cand.push_back("o"); break;
		case '7':
			cand.push_back("p"); cand.push_back("q"); cand.push_back("r"); cand.push_back("s"); break;
		case '8':
			cand.push_back("t"); cand.push_back("u"); cand.push_back("v"); break;
		case '9':
			cand.push_back("w"); cand.push_back("x"); cand.push_back("y"); cand.push_back("z"); break;
		default:
			break;
		}
	}
	void backTrace(string digits, int index, vector<string>& str) {
		if (index == digits.size()) {
			if (str.size() == 0)    return;
			string res = "";
			for (int i = 0; i < str.size(); i++)
				res += str.at(i);
			rl.push_back(res);
		} else {
			vector<string> cand;
			generateCand(digits, index, cand);
			for (int i = 0; i < cand.size(); i++) {
				str.push_back(cand.at(i));
				backTrace(digits, index+1, str);
				str.pop_back();
			}
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> str;
		backTrace(digits, 0, str);
		return rl;
	}
};