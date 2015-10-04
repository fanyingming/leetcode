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

