/*
** we use dynamic programming to solve this problem.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
	int n, m;
	long long left, top, bottom, maxn;
	long long **scores;
	long long *scoresCol;
	vector< vector<int> > grid;
	bool isError = false;
	//input data and alloc memory dynamically.
	cin >> n >> m;

	if (n <= 0 || m <= 0) {
		cout<<"-1"<<endl;
		return -1;
	}

	scores = (long long **)malloc(sizeof(long long*)*n);
	scoresCol = (long long *)malloc(sizeof(long long)*m);
	for (int y = 0; y < n; y++) {
		vector<int> rowList;
		scores[y] = (long long *)malloc(sizeof(long long)*m);
		for (int x = 0; x < m; x++){
			int t;
			cin >> t;
			if (t < -1) {
				isError = true;
				goto end;
			}
			rowList.push_back(t);
		}
		grid.push_back(rowList);
	}
	//dynamic programming method
	for (int x = 0; x < m; x++){
		//top to bottom
		for (int y = 0; y < n; y++) {
			if (grid[y][x] == -1) {
				scores[y][x] = -1;
				continue;
			}
			
			if (y == 0)
				top = -1;
			else
				top = scores[y - 1][x] == -1 ? -1 : scores[y - 1][x];
			if (x == 0)
				left = -1;
			else
				left = scores[y][x - 1];
			maxn = max(left, top);
			if (maxn == -1 && x == 0) {
				scores[y][x] = grid[y][x];
				continue;
			}
			if (maxn == -1)
				scores[y][x] = -1;
			else
				scores[y][x] = grid[y][x] + maxn;
		}
		//bottom to top
		for (int y = n - 1; y >= 0; y--) {
			if (grid[y][x] == -1) {
				scores[y][x] = -1;
				scoresCol[y] = -1;
				continue;
			}

			if (y == n - 1)
				bottom = -1;
			else
				bottom = scoresCol[y + 1];
			if (x == 0)
				left = -1;
			else
				left = scores[y][x - 1];
			maxn = max(left, bottom);
			if (maxn == -1 && x == 0) {
				scoresCol[y] = grid[y][x];
			} else {
				if (maxn == -1)
					scoresCol[y] = -1;
				else
					scoresCol[y] = maxn + grid[y][x];
			}
			scores[y][x] = max(scoresCol[y], scores[y][x]);
		}
		if (scores[0][x] == -1 && scores[n-1][x] != -1) {
			scores[0][x] = grid[0][x];
		} else if (scores[n - 1][x] == -1 && scores[0][x] != -1) {
			scores[n - 1][x] = grid[n-1][x];
		}
		//if current column can't be acrossed, means no way to reach right border. 
		bool noWay = true;
		for (int i = 0; i < n; i++) {
			if (scores[i][x] >= 0) {
				noWay = false;
				break;
			}
		}
		if (noWay) {
			cout<<"-1"<<endl;
			isError = false;
			goto end;
		}
	}

	for (int i = 0; i < n; i++)
		maxn = max(maxn, scores[i][m - 1]);
	cout << maxn << endl;
end:
	if (scoresCol)
		free(scoresCol);
	for (int y = 0; y < n; y++)
		if (scores[y])
			free(scores[y]);
	if (scores)
		free(scores);
	return isError ? -1 : 0;
}