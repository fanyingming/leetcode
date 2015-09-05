#define SRC(x, y) *(*(matrix + y) + x)
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int y, x;
    int row_zero = 1, column_zero = 1;
    
    for (y = 0; y < matrixRowSize; y++) {
        for (x = 0; x < matrixColSize; x++) {
            if (SRC(x, y) == 0) {
                SRC(x, 0) = SRC(0, y) = 0;
                if (x == 0) column_zero = 0;
                if (y == 0) row_zero = 0;
            }
        }
    }
    
    for (y = 1; y < matrixRowSize; y++) {
        if (SRC(0, y) == 0) {
            for (x = 1; x < matrixColSize; x++)
                SRC(x, y) = 0;
        }
    }
    for (x = 1; x < matrixColSize; x++) {
        if (SRC(x, 0) == 0) {
            for (y = 1; y < matrixRowSize; y++)
                SRC(x, y) = 0;
        }
    }
    if (row_zero == 0) {
        for (x = 0; x < matrixColSize; x++)
                SRC(x, 0) = 0;
    }
    if (column_zero == 0) {
        for (y = 0; y < matrixRowSize; y++)
                SRC(0, y) = 0;
    }
}