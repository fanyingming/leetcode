int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int path[100][100];
    for (int y = 0; y < obstacleGridRowSize; y++){
            for (int x = 0; x < obstacleGridColSize; x++) {
                if (obstacleGrid[y][x] == 1) {
                    path[y][x] = 0;
                    continue;
                }
                if (x == 0 && y == 0) {
                    path[y][x] = 1;
                } else if (x == 0) {
                    path[y][x] = path[y-1][x]; 
                } else if (y == 0) {
                    path[y][x] = path[y][x-1];
                } else {
                    path[y][x] = path[y][x-1] + path[y-1][x];
                }
            }
        }
        return path[obstacleGridRowSize-1][obstacleGridColSize-1];
}