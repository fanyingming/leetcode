class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x, y;
        
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        x = matrix[0].size()-1;
        y = 0;
        
        while (x >= 0 && y <= matrix.size()-1) {
            if (target > matrix[y][x]) {
                y++;
            } else if (target < matrix[y][x]) {
                x--;
            } else {
                return true;
            }
        }
        return false;
    }
};