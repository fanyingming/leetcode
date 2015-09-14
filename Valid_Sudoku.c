class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> htable;
        for (int i = 0; i < board.size(); i++) {
            htable.clear();
            for (int j = 0; j < board.at(i).size(); j++) {
                char c = board.at(i).at(j);
                if (c >= '1' && c <= '9') {
                    if (htable.find(c) == htable.end())
                        htable.insert(c);
                    else
                        return false;
                }
            }
        }
        
        for (int i = 0; i < board.at(0).size(); i++) {
            htable.clear();
            for (int j = 0; j < board.size(); j++) {
                char c = board.at(j).at(i);
                if (c >= '1' && c <= '9') {
                    if (htable.find(c) == htable.end()) 
                        htable.insert(c);
                    else
                        return false;
                }
            }
        }
        int col, row, x, y;
        for (col = row = 0; col < 9 && row < 9; ) {
            htable.clear();
            for (y = 0; y < 3; y++) {
                for (x = 0; x < 3; x++) {
                    char c = board.at(row+y).at(col+x);
                    if (c >= '1' && c <= '9') {
                        if (htable.find(c) == htable.end())
                            htable.insert(c);
                        else
                            return false;
                    }
                }
            }
            col += 3;
            if (col == 9) {
                col = 0;
                row += 3;
            }
        }
        return true;
    }
};