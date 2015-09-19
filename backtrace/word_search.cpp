typedef struct Position {
    int x;
    int y;
}Position;

class Solution {
public:
    vector<vector<int>> used;

    void constructCand(vector<vector<char>>& board, vector<vector<int>>& used, string word, string find, Position pos, vector<Position>& cand) {
        char next_char = word.at(find.size());
        int x = pos.x, y = pos.y;
        if (y > 0 && used[y-1][x] == 0 && board[y-1][x] == next_char) {// up
            Position p = {x, y-1};
            cand.push_back(p);
        }
        if (y+1 < board.size() && used[y+1][x] == 0 && board[y+1][x] == next_char) {//down
            Position p = {x, y+1};
            cand.push_back(p);
        }
        if (x > 0 && used[y][x-1] == 0 && board[y][x-1] == next_char) {//left
            Position p = {x-1, y};
            cand.push_back(p);
        }
        if (x+1 < board[y].size() && used[y][x+1] == 0 && board[y][x+1] == next_char) {//right
            Position p = {x+1, y};
            cand.push_back(p);
        }
    }
    
    bool backTrace(vector<vector<char>>& board, vector<vector<int>>& used, string word, string find, Position pos) {
        if (find.size() == word.size()) {
            return true;
        } else {
            vector<Position> cand;
            constructCand(board, used, word, find, pos, cand);
            for (int i = 0; i < cand.size(); i++) {
                Position cand_pos = cand[i];
                int x = cand_pos.x, y = cand_pos.y;
                find += board[y][x];
                used[y][x] = 1;
                if (backTrace(board, used, word, find, cand_pos))
                    return true;
                used[y][x] = 0;
                find.pop_back();
            }
            return false;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board.at(0).size() == 0 || word.size() == 0)
            return false;
            
        for (int i = 0; i < board.size(); i++) {
            vector<int> v(board[i].size(), 0);
            used.push_back(v);
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(i).size(); j++) {
                Position t = {j, i};
                char current = board[i][j];
                if (current != word.at(0))
                    continue;
                    
                for (int i = 0; i < board.size(); i++) 
                    for (int j = 0; j < board[i].size(); j++)
                        used[i][j] = 0;
                    
                string find;
                find += current;
                used[i][j] = 1;
                if (backTrace(board, used, word, find, t))
                    return true;
            }
        }
        return false;
    }
};