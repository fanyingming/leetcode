//longest common subsequence
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

vector< vector<int> > matrix;
vector< vector<int> > mark;

int lcs(string str1, string str2, int index1, int index2) {
	if (index1 < 0 || index2 < 0)
		return 0;
	if (matrix[index1][index2] != -1)
		return matrix[index1][index2];
	if (str1[index1] == str2[index2]) {
		mark[index1][index2] = 0;
		matrix[index1][index2] = lcs(str1, str2, index1 - 1, index2 - 1) + 1;
		return matrix[index1][index2];
	}
	else {
		int size1 = lcs(str1, str2, index1 - 1, index2);
		int size2 = lcs(str1, str2, index1, index2 - 1);

		if (size1 > size2)
			mark[index1][index2] = 1;
		else
			mark[index1][index2] = -1;

		matrix[index1][index2] = max(size1, size2);
		return matrix[index1][index2];
	}
}

string caller(string str1, string str2) {
	for (int i = 0; i < str1.size(); i++)  {
		vector<int> row_matrix;
		vector<int> row_mark;
		for (int j = 0; j < str2.size(); j++) {
			row_matrix.push_back(-1);
			row_mark.push_back(3);
		}
		matrix.push_back(row_matrix);
		mark.push_back(row_mark);
	}

	lcs(str1, str2, str1.size() - 1, str2.size() - 1);

	int index1 = str1.size() - 1;
	int index2 = str2.size() - 1;
	string res;
	while (index1 >= 0 && index2 >= 0) {
		if (mark[index1][index2] == 0) {
			res += str1[index1];
			index1--;
			index2--;
		}
		else if (mark[index1][index2] == -1) {
			index2--;
		}
		else if (mark[index1][index2] == 1) {
			index1--;
		}
		else {
			assert(0);
		}
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	string str1, str2;
	cin >> str1;
	cin >> str2;
	string res = caller(str1, str2);
	cout<<endl << res << endl;
}