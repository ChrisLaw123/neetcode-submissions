class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //rows & cols
        vector<unordered_set<char>> square (9);
        for (int i{}; i < board.size(); i++) {
            unordered_set<char> row;
            unordered_set<char> col;
            
            for (int j{}; j < board.size(); j++) {
                if (row.contains(board[i][j])) {
                    return false;
                } else if (board[i][j] != '.'){
                    row.insert(board[i][j]);
                }

                if (col.contains(board[j][i])) {
                    return false;
                } else if (board[j][i] != '.'){
                    col.insert(board[j][i]);
                }

                int squarepos = (i/3) * 3 + (j/3);
                if (square[squarepos].contains(board[i][j])) {
                    return false;
                } else if (board[i][j] != '.'){
                    square[squarepos].insert(board[i][j]);
                }

            }
        }
        
        //squares
      

        return true;

    }
};
