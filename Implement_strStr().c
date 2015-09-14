class Solution {
public:
	int strStr(string haystack, string needle) {
	    int j;
	    if (haystack.size() == 0 && needle.size() == 0)
	        return 0;
	    if (needle.size() == 0)
	        return 0;
		if (haystack.size() == 0 || needle.size() > haystack.size())
			return -1;
		for (int i = 0; i <= haystack.size() - needle.size(); i++) {
			for (j = 0; j < needle.size(); j++) {
				if (haystack[i + j] != needle[j])
					break;
			}
			if (j == needle.size()) {
				return i;
			}
		}
		return -1;
	}
};
