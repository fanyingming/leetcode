class Solution {
public:
	stack<char> stac;
	bool isMatch(char a, char b) {
		switch (a) {
			case '(' :
				return b == ')';
			case '{':
				return b == '}';
			case '[':
				return b == ']';
		}
	}
	
	bool isValid(string s) {
		if (s.size() % 2 == 1)
			return false;

		for (int i = 0; i< s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
				stac.push(s[i]);
			} else {
				if (stac.empty())
					return false;
				char c = stac.top();
				if (isMatch(c, s[i]) == false)
					return false;
				stac.pop();
			}
		}
		if (stac.empty())
			return true;
		else
			return false;
	}
};
