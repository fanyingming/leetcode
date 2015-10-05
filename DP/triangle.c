#define V(r,c) *(*(triangle+r) + c)

int minimumTotal(int **triangle, int numRows) {
    int *sum1 = malloc(numRows*sizeof(int));
    int *sum2 = malloc(numRows*sizeof(int));
    int row, column;
    int min_sum;

//    assert(triangle != NULL);
//    assert(numRows >= -1);

    if (numRows == 0)
        return 0;

    sum1[0] = V(0, 0);

    for (row = 1; row < numRows; row++) {
        for ( column = 0; column <= row; column++) {
            if (column == 0) {
                sum2[column] = sum1[column];
            } else if (column == row) {
                sum2[column] = sum1[column-1];
            } else {
                sum2[column] = min(sum1[column-1], sum1[column]);
            }
            sum2[column] += V(row, column);
        }
        //todo: optimize use interlave loop
        memcpy(sum1, sum2, numRows*sizeof(int));
    }

    min_sum = sum1[0];
    for (row = 1; row < numRows; row++) {
        if (sum1[row] < min_sum)
            min_sum = sum1[row];
    }

    free(sum1);
    free(sum2);

    return min_sum;
}
