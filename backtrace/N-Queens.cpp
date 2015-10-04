class Solution {
public:
	vector<vector<string>> return_list;

	int is_ok(int *a, int k, int v, int n) {
		int i, j;
		int column_v;
		//top
		i = k-1;
		while (i >= 0) {
			if (a[i--] == v)
				return 0;
		}
		//top left;
		i = k-1;
		column_v = v-1;
		while (i >= 0 && column_v >= 0) {
			if (a[i--] == column_v--) {
				return 0;
			}
		}
		//top right;
		i = k-1;
		column_v = v-1;
		while (i >= 0 && v+1 <= n-1) {
			if (a[i] == v+1) {
				return 0;
			} else {
				i--;
				v++;
			}
		}
		return 1;
	}
	
	void construct_cand(int *a, int k, int n, int *c, int *ncand) {
		int i, j;

		for (i = 0; i < n; i++) {
			if (is_ok(a, k, i, n)) {
				c[*ncand] = i;
				(*ncand)++;
			}
		}
	}

	int is_a_solution(int *a, int k, int n) {
		return k+1 == n;
	}

	void process_solution(int *a, int n) {
		int i, j;
		string str;
		vector<string> sol;

		sol.clear();
		for ( i = 0; i < n; i++) {
			str.clear();
			for ( j = 0; j < n; j++) {
				if (a[i] == j) {
					str += "Q";
				} else {
					str += ".";
				}
			}
			sol.push_back(str);
		}
		return_list.push_back(sol);
	}

	void backtrack(int *a, int k, int n) {
		int *c = (int *)malloc(sizeof(int)*n);
		int ncand = 0;
		int i;

		if (is_a_solution(a, k, n)) {
			process_solution(a,n);
		} else {
			k = k+1;
			construct_cand(a, k, n, c, &ncand);
			for (i = 0; i < ncand; i++) {
				a[k] = c[i];
				backtrack(a, k, n);
			}
		}
		free(c);
	}

	void nQueen(int n) {
		int *a = (int *)malloc(sizeof(int)*n);
		backtrack(a, -1, n);
		free(a);
	}

	vector<vector<string>> solveNQueens(int n) {  
		int *a = (int *)malloc(sizeof(int)*n);
		return_list.clear();
		backtrack(a, -1, n);
		free(a);
		return return_list;
	}
};