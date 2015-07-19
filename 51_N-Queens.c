#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
 * k, row num; v, value; n, total .
 */
bool is_ok(int *a, int k, int v, int n) {
	int i, j;
	int column_v;
	//top
	i = k-1;
	while (i >= 0) {
		if (a[i--] == v)
			return false;
	}
	//top left;
	i = k-1;
	column_v = v-1;
	while (i >= 0 && column_v >= 0) {
		if (a[i--] == column_v--) {
			return false;
		}
	}
	//top right;
	i = k-1;
	column_v = v-1;
	while (i >= 0 && v+1 <= n-1) {
		if (a[i] == v+1) {
			return false;
		} else {
			i--;
			v++;
		}
	}
	return true;
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

bool is_a_solution(int *a, int k, int n) {
	return k==n;
}

void process_solution(int *a, int n) {
	int i, j;

	for ( i = 0; i < n; i++) {
		for ( j = 0; j < n; j++) {
			if (a[i] == j)
				printf("Q\t");
			else
				printf("*\t");
		}
		printf("\n");
	}

	printf("---\n");
}

void backtrack(int *a, int k, int n) {
	int *c = (int *)malloc(sizeof(int)*n);
	int ncand;
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

int main() {
	int n;

	while (scanf("%d", &n) != EOF) {
		nQueen(n);
	}
}