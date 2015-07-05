#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) {
            if (word == "") {
                return true;
            } else {
                return false;
            }
        }
        
        rows = board.size(), cols = board[0].size();
        for (int row = 0; row != rows; row++) {
            for (int col = 0; col != cols; col++) {
                if (exist(board, word, row, col, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    int rows, cols;
    bool exist(vector<vector<char>> &board, string &word, int row, int col, int pos) {
        if (board[row][col] != word[pos] || board[row][col] == ' ') {
            return false;
        } else if (pos == word.size()-1) {
            return true;
        }
        
        char c = board[row][col];
        board[row][col] = ' ';
        bool nextExist = (row > 0 && exist(board, word, row-1, col, pos+1))
            || (row < rows-1 && exist(board, word, row+1, col, pos+1))
            || (col > 0 && exist(board, word, row, col-1, pos+1))
        || (col < cols-1 && exist(board, word, row, col+1, pos+1));
        board[row][col] = c;
        return nextExist;
    }
};

int main() {
    
    return 0;
}

