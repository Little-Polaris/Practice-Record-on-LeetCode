#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() / 2; i++) {
            for (int j = 0; j < matrix.size() - 1 - i * 2; j++) {
                int temp = matrix[0 + i][0 + j + i];
                matrix[0 + i][0 + j + i] = matrix[matrix.size() - 1 - j - i][0 + i];
                matrix[matrix.size() - 1 - j - i][0 + i] = matrix[matrix.size() - 1 - i][matrix.size() - 1 - j - i];
                matrix[matrix.size() - 1 - i][matrix.size() - 1 - j - i] = matrix[0 + j + i][matrix.size() - 1 - i];
                matrix[0 + j + i][matrix.size() - 1 - i] = temp;
            }
        }
    }
};

int main() {
    vector<vector<int>> vv;
    vv = { {1,2,3},{4,5,6},{7,8,9} };
    /*vv = {  { 5, 1, 9, 11 },
            { 2, 4, 8, 10 },
            { 13, 3, 6, 7 },
            { 15, 14, 12, 16} };*/
    Solution().rotate(vv);
    for (auto i : vv) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}