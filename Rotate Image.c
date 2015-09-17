#include <stdio.h>

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int x, y, t;
    
    for (y = 0; y < matrixRowSize/2; y++) {
        for (x = 0; x < matrixColSize; x++) {
            t = *(*(matrix + y) + x);
            *(*(matrix + y) + x) = *(*(matrix + matrixRowSize-1-y) + x);
            *(*(matrix + matrixRowSize-1-y) + x) = t;
        }
    }

    for (y = 0; y < matrixRowSize; y++) {
        for (x = y+1; x < matrixColSize; x++) {
            t = *(*(matrix + y) + x);
            *(*(matrix + y) + x) = *(*(matrix + x) + y);
            *(*(matrix + x) + y) = t;
        }
    }
        
}
int *a[3]

int (*a)[3]
int main() {
	int a1[3] = {1,2,3};
	int a2[3] = {4,5,6};
	int a3[3] = {7,8,9};
	int *a[3] = {a1, a2, a3};
	int x, y;

	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			printf("%d\t",*(*(a+y)+x));
		}
		printf("\n");
	}

	printf("--\n");

	rotate(a, 3, 3);

	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			printf("%d\t",*(*(a+y)+x));
		}
		printf("\n");
	}
}
