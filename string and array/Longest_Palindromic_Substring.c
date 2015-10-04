/*
** 为什么这样做？这样做为什么快？暴力和这种方法都是O(n^2)啊。
*/
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
			if (r - l + 1 > res.size()) {
				res = "";
				for (int j = l; j <= r; j++)
					res += s[j];
			}

			for (l = i, r = i + 1; l >= 0 && r < s.size(); l--, r++)
				if (s[l] != s[r])
					break;
			l++;
			r--;
			if (r - l + 1 > res.size()) {
				res = "";
				for (int j = l; j <= r; j++)
					res += s[j];
			}
		}
		return res;
	}
};

//below is brute force method.
bool is_palindrome(char* s, int begin, int end) {
	int i;
	for (i = 0; i <= (end - begin) / 2; i++) {
		if (s[begin+i] != s[end - i])
			return false;
	}
	return true;
}

char* longestPalindrome(char* s) {
	char* res = (char *)malloc(sizeof(char) * 1001);
	int max_len = 0;
	int i, j;
	int begin, end;

	for (i = 0; i < strlen(s); i++) {
		for (j = strlen(s)-1; j >= i; j--) {
			if (max_len > j - i + 1)
				break;
			if (is_palindrome(s, i, j)) {
				int len = j - i + 1;
				if (len > max_len) {
					max_len = len;
					begin = i;
					end = j;
				}
			}
		}
	}

	memcpy(res, s + begin, max_len);
	res[max_len] = 0;
	return res;
}

