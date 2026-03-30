class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       
        for (int i = 0; i < 9; i++) {
            vector<bool> seen(10, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if (seen[num]) return false;
                seen[num] = true;
            }
        }
        
      
        for (int j = 0; j < 9; j++) {
            vector<bool> seen(10, false);
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if (seen[num]) return false;
                seen[num] = true;
            }
        }
        
       
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                vector<bool> seen(10, false);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[boxRow + i][boxCol + j];
                        if (c == '.') continue;
                        int num = c - '0';
                        if (seen[num]) return false;
                        seen[num] = true;
                    }
                }
            }
        }
        
        return true;
    }
};
