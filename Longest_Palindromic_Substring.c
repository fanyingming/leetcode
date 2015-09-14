class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		int l, r;
		string res = "";

		for (int i = 0; i < s.size(); i++) {
			for (l = i - 1, r = i + 1; l >= 0 && r < s.size(); l--, r++)
				if (s[l] != s[r])	
					break;

			l++;
			r--;
			if (r - l + 1 > res.size()){
				res = "";
				for (int j = l; j <= r; j++)
					res += s[j];
			}

			for (l = i, r = i + 1; l >= 0 && r < s.size(); l--, r++)
				if (s[l] != s[r])
					break;

			l++;
			r--;
			if (r - l + 1 > res.size()){
				res = "";
				for (int j = l; j <= r; j++)
					res += s[j];
			}
			
		}
		return res;
	}
};
