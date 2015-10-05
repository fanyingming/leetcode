#define MAX_NUM = 0x1fffffff

int min_my(int a, int b) {
    return a < b ? a : b;
}

#define SRC(x, y) *(*(grid + y) + x)
#define SRC_DP(x,y) *(dp_grid+y*gridColSize+x)

int dp(int** grid, int gridRowSize, int gridColSize, int x, int y, int *dp_grid) {
    int left, top;
    int min;

    if (SRC_DP(x,y))
        return SRC_DP(x,y);

    if (x == 0 && y == 0) {
        SRC_DP(x,y) = SRC(0,0);
        return SRC(0, 0);
    }

    left = top = 0x1fffffff;

    if (x > 0)
        left = dp(grid, gridRowSize, gridColSize, x-1, y, dp_grid) + SRC(x, y);
    if (y > 0)
        top = dp(grid, gridRowSize, gridColSize, x, y-1, dp_grid) + SRC(x, y);

    min = min_my(left, top);
    SRC_DP(x,y) = min;

    return min;
}

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int *dp_grid = malloc(sizeof(int)*gridRowSize*gridColSize);

    memset(dp_grid, 0, sizeof(int)*gridRowSize*gridColSize);
    return dp(grid, gridRowSize, gridColSize, gridColSize-1, gridRowSize-1, dp_grid);
}
