#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

enum {
	LEFT = 1,
	RIGHT,
	UP,
	DOWN
};
#define SRC(x,y) rl.at(y)[x]
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<int> row(n, 0);
		vector<vector<int> > rl(n, row);

		int dir, count, index;
		int i, x, y;

		if (n == 0)
			return rl;
		if (n == 1) {
			rl.at(0)[0] = 1;
			return rl;
		}
		dir = RIGHT;
		count = n - 1;
		index = 1;
		x = y = 0;

		while (index <= n*n) {
			if (count == 0) {
				SRC(x, y) = index;
				break;
			}
			switch (dir) {
			case RIGHT: {
				for (i = 1; i <= count; i++)
					SRC(x++, y) = index++;
				dir = DOWN;
				break;
			}
			case DOWN: {
				for (i = 1; i <= count; i++)
					SRC(x, y++) = index++;
				dir = LEFT;
				break;
			}
			case LEFT: {
				for (i = 1; i <= count; i++)
					SRC(x--, y) = index++;
				dir = UP;
				break;
			}
			case UP: {
				for (i = 1; i <= count; i++)
					SRC(x, y--) = index++;
				dir = RIGHT;
				count -= 2;
				y++; x++;
				break;
			}
			}
		}
		return rl;
	}
};
/*
int main() {
	int n;
	cin >> n;
	Solution obj;
	vector< vector<int> > rl = obj.generateMatrix(n);

	for (int y = 0; y < rl.size(); y++){
		for (int x = 0; x < rl.at(y).size(); x++) {
			cout << rl.at(y)[x] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}*/
