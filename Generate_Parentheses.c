class Solution {
public:
	vector<string> rl;
	void helper(int l, int r, string str) {
		if (l > r)
			return;
		if (l == 0 && r == 0) {
			rl.push_back(str);
			return;
		}
		if (l > 0)
			helper(l-1, r, str+'(');
		if (r > 0)
			helper(l, r - 1, str + ')');
	}
	vector<string> generateParenthesis(int n) {
		rl.clear();
		if (n <= 0)
			return rl;
		helper(n, n, "");
		return rl;
	}
};
