class Solution {
public:
    int fractional(int n) {
		int sum = 1;
		for (int i = 2; i <= n; i++)
			sum *= i;
		return sum;
	}
	string getPermutation(int n, int k) {
		vector<int> nums, res;
		string str;
		
		for (int i = 1; i <= n; i++)
			nums.push_back(i);
		if (n <= 0 || k <= 0 || k > fractional(nums.size()))
			return ""; 
		if (fractional(nums.size()) == k) {
			for (int i = nums.size() - 1; i >= 0; i--)
				res.push_back(nums.at(i));
			k = 0;
		}
		
		while (k > 0) {
			int num1 = fractional(nums.size() - 1);
			int a = k / num1;
			int b = k % num1;

			if (b == 0) {
				res.push_back(nums.at(a - 1));
				nums.erase(nums.begin() + a - 1);
				for (int i = nums.size() - 1; i >= 0; i--)
					res.push_back(nums.at(i));
				break;
			} else if (b == 1 && a == 0) {
				for (int i = 0; i < nums.size(); i++)
					res.push_back(nums.at(i));
				break;
			} else {
				res.push_back(nums.at(a));
				nums.erase(nums.begin() + a);
				k = b;
			}
		}

		for (int i = 0; i < res.size(); i++)
			str += res.at(i) + '0';
		return str;
	}
};