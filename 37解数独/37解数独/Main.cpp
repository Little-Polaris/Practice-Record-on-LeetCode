#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int matrix[10][10] = {0};
        vector<set<int>> row_used(10, set<int>());
        vector<set<int>> col_used(10, set<int>());
        vector<set<int>> block_used(10, set<int>());
        vector<set<int>>row_unused(10,set<int>());
        vector<set<int>>col_unused(10,set<int>());
        vector<set<int>>block_unused(10,set<int>());
        for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                if (board[i - 1][j - 1] != '.')
                {
                    matrix[i][j] = board[i - 1][j - 1] - '0';
                }
            }
        }
        for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                if (matrix[i][j] != 0)
                {
                    row_used[i].insert(matrix[i][j]);
                }
                if (matrix[j][i] != 0)
                {
                    col_used[i].insert(matrix[j][i]);
                }
            }
        }
        int count = 1;
        for (int i = 1; i < 10; i += 3)
        {
            for (int j = 1; j < 10; j += 3, count++)
            {
                for (int k = i; k < i + 3; k++)
                {
                    for (int l = j; l < j + 3; l++)
                    {
                        if (matrix[k][l] != 0)
                        {
                            block_used[count].insert(matrix[k][l]);
                        }
                    }
                }
                set<int> temp = { 1,2,3,4,5,6,7,8,9 };
                set_difference(temp.begin(), temp.end(), block_used[count].begin(), block_used[count].end(), inserter(block_unused[count], block_unused[count].begin()));
            }
        }
        for (int i = 1; i < 10; i++)
        {
            set<int> temp = {1,2,3,4,5,6,7,8,9 };
            set_difference(temp.begin(), temp.end(), row_used[i].begin(), row_used[i].end(), inserter(row_unused[i], row_unused[i].begin()));
            set_difference(temp.begin(), temp.end(), col_used[i].begin(), col_used[i].end(), inserter(col_unused[i], col_unused[i].begin()));
        }
        int flag = 1;
        while (flag)
        {
            for (int i = 1; i < 10; i += 3)
            {
                for (int j = 1; j < 10; j += 3)
                {
                    for (int k = i; k < i + 3; k++)
                    {
                        for (int l = j; l < j + 3; l++)
                        {
                            if (matrix[k][l] == 0)
                            {
                                set<int> options;
                                set<int> temp;
                                int index = i / 3 * 3 + j / 3 + 1;
                                set_intersection(row_unused[k].begin(), row_unused[k].end(), col_unused[l].begin(), col_unused[l].end(), inserter(temp, temp.begin()));
                                set_intersection(temp.begin(), temp.end(), block_unused[index].begin(), block_unused[index].end(), inserter(options, options.begin()));
                                if (options.size() == 1)
                                {
									matrix[k][l] = *options.begin();
                                    row_unused[k].erase(*options.begin());
                                    col_unused[l].erase(*options.begin());
                                    block_unused[index].erase(*options.begin());
								}
                            }
                        }
                    }
                }
            }
            int flag1 = 0;
            for (int i = 1; i < 10; i++)
            {
                for (int j = 1; j < 10; j++)
                {
                    if (matrix[i][j] == 0)
                    {
						flag1 = 1;
                        break;
					}
                }
                if (flag1)
                {
                    break;
                }
            }
            if (flag1 == 0)
            {
                flag = 0;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                board[i][j] = matrix[i + 1][j + 1] + '0';
            }
        }
        return;
    }
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }

private:
    bool dfs(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true; // 遍历完成，返回true
        if (col == 9) return dfs(board, row + 1, 0); // 遍历一行结束，继续遍历下一行

        if (board[row][col] != '.') return dfs(board, row, col + 1); // 当前位置已填，继续下一个位置

        // 枚举1到9来填数字，验证填入的数字是否符合数独的要求
        for (char num = '1'; num <= '9'; ++num) {
            if (isValid(board, row, col, num)) {
                board[row][col] = num; // 填入数字
                if (dfs(board, row, col + 1)) return true; // 填入成功，继续下一个位置
                board[row][col] = '.'; // 回溯
            }
        }

        return false; // 1~9填入失败，需要回溯
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // 检查行和列是否符合要求
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == num || board[row][i] == num) return false;
        }

        // 检查3*3方格是否符合要求
        int square_r = (row / 3) * 3;
        int square_c = (col / 3) * 3;

        for (int i = square_r; i < square_r + 3; ++i) {
            for (int j = square_c; j < square_c + 3; ++j) {
                if (board[i][j] == num) return false;
            }
        }

        return true;
    }
}


int main()
{
    vector<vector<char>> board =
        {{'.', '.', '9', '7', '4', '8', '.', '.', '.'},
        {'7', '.', '.', '.', '.', '.', '.', '.', '.'}, 
        {'.', '2', '.', '1', '.', '9', '.', '.', '.'}, 
        {'.', '.', '7', '.', '.', '.', '2', '4', '.'}, 
        {'.', '6', '4', '.', '1', '.', '5', '9', '.'}, 
        {'.', '9', '8', '.', '.', '.', '3', '.', '.'}, 
        {'.', '.', '.', '8', '.', '3', '.', '2', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', '.', '6'}, 
        {'.', '.', '.', '2', '7', '5', '9', '.', '.'}};
    Solution().solveSudoku(board);
    for (auto i : board)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
	return 0;
}