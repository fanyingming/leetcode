class Solution {
public:
	string int2str(int int_temp) {
		char num[100];
		string res;
		sprintf(num, "%d", int_temp);
		res = num;
		return res;
	}

	string countAndSay(int n) {
		string res, tstr;
		int count;
		char lastc;

		if (n <= 0) return "";
		res = "1";
		for (int i = 2; i <= n; i++) {
			lastc = res[0];
			count = 1;
			tstr = "";
			for (int j = 1; j < res.size(); j++) {
				if (res[j] == lastc) {
					count++;
				}
				else {
					tstr += int2str(count);
					tstr += lastc;
					count = 1;
					lastc = res[j];
				}
			}
			//last sub string.
			tstr += int2str(count);
			tstr += lastc;
			res = tstr;
		}
		return res;
	}
};