#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int matrix[9][9] = { 0 };
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    matrix[i][j] = board[i][j] - '0';
                }
            }
        }
        for (int i = 0; i < 9; i++)
        {
            int visited1[10] = { 0 };
            int visited2[10] = { 0 };
            for (int j = 0; j < 9; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (visited1[matrix[i][j]] == 1)
                    {
						return false;
					}
					visited1[matrix[i][j]] = 1;
				}
                if (matrix[j][i] != 0)
                {
                    if (visited2[matrix[j][i]] == 1)
                    {
                        return false;
                    }
                    visited2[matrix[j][i]] = 1;
                }
            }
        }
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                int visited[10] = { 0 };
                for (int k = i; k < i + 3; k++)
                {
                    for (int l = j; l < j + 3; l++)
                    {
                        if (matrix[k][l] != 0)
                        {
                            if (visited[matrix[k][l]] == 1)
                            {
					            return false;
				            }
				            visited[matrix[k][l]] = 1;
						}
					}
				}
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> board = 
        { {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
        , {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
        , {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
        , {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
        , {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
        , {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
        , {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
        , {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
        , {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
    cout << Solution().isValidSudoku(board) << endl;
	return 0;
}