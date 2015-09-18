class Solution {
public:
    int path[100][100];
    int uniquePaths(int m, int n) {
        for (int y = 0; y < m; y++){
            for (int x = 0; x < n; x++) {
                if (x == 0 || y == 0) {
                    path[y][x] = 1;
                } else {
                    path[y][x] = path[y][x-1] + path[y-1][x];
                }
            }
        }
        return path[m-1][n-1];
    }
};