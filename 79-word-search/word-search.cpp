class Solution {
private:

    bool solve(vector<vector<char>>& board, string word,
               int row, int col, int index) {

        // Base case
        if (index == word.length()) {
            return true;
        }

        // Boundary condition
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size()) {
            return false;
        }

        // Character does not match
        if (board[row][col] != word[index]) {
            return false;
        }

        // Mark current cell as visited
        char original = board[row][col];
        board[row][col] = '#';

        // Try all 4 directions

        // Down
        if (solve(board, word, row + 1, col, index + 1))
            return true;

        // Up
        if (solve(board, word, row - 1, col, index + 1))
            return true;

        // Right
        if (solve(board, word, row, col + 1, index + 1))
            return true;

        // Left
        if (solve(board, word, row, col - 1, index + 1))
            return true;

        // Backtracking
        board[row][col] = original;

        return false;
    }

public:

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        // Try every cell as starting point
        for (int row = 0; row < rows; row++) {

            for (int col = 0; col < cols; col++) {

                if (board[row][col] == word[0]) {

                    if (solve(board, word, row, col, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
