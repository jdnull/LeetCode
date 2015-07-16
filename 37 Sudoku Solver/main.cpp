#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> v(9, 0);
        vector<vector<int>> used1(9, v), used2(9, v), used3(9, v);
        int dotCount = 0;
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                } else {
                    dotCount++;
                }
        solveSudokuHelper(board, dotCount, used1, used2, used3);
    }
    
    bool solveSudokuHelper(vector<vector<char>>& board, int dotCount, vector<vector<int>>& used1, vector<vector<int>>& used2, vector<vector<int>>& used3) {
        if (dotCount == 0) {
            return true;
        }
        bool ret = false;
        
        int i, j;
        for (i = 0; i < board.size(); i++) {
            bool flag = false;
            for (j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        
        for (int k = 0; k < 9; k++) {
            if (used1[i][k] < 1 && used2[j][k] < 1 && used3[i/3*3+j/3][k] < 1) {
                board[i][j] = k + 1 + '0';
                used1[i][k]++, used2[j][k]++, used3[i/3*3+j/3][k]++;
                
                ret = solveSudokuHelper(board, dotCount-1, used1, used2, used3);
                if (ret) {
                    break;
                } else {
                    board[i][j] = '.';
                    used1[i][k]--, used2[j][k]--, used3[i/3*3+j/3][k]--;
                }
            }
        }
        
        return ret;
    }
};

int main() {
    vector<char> v(9, '.');
    vector<vector<char>> board(9, v);
    
    string ss[9] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    //             {"534678912","672195348","198342567","859761423","426853791","713924856","961537284","287419635","345286179"}
//    string ss[9] = {"..4678912","672195348","198342567","859761423","426853791","713924856","961537284","287419635","345286179"};
    vector<string> demo(ss, &ss[9]);
    for (int i = 0; i < demo.size(); i++) {
        for (int j = 0; j < demo[0].length(); j++) {
            if (demo[i][j] != '.') {
                board[i][j] = demo[i][j];
            }
        }
    }
    
    Solution s;
    s.solveSudoku(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}