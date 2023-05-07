#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
        {
            return s;
        }
        char mat[1000][1000] = { 0 };
        int x = 0, y = 0;
        mat[0][0] = s[0];
        int visited = 1;
        for (int i = 0; visited != s.size(); i++)
        {
            if (x == 0)
            {
                for (int j = 0; j < numRows - 1; j++)
                {
                    x++;
                    mat[x][y] = s[visited];
                    visited++;
                    if (visited == s.size())
                    {
                        break;
                    }
                }
            }
            else
            {
                while (x)
                {
                    x--;
                    y++;
                    mat[x][y] = s[visited];
                    visited++;
                    if (visited == s.size())
                    {
                        break;
                    }
                }
            }
        }
        s.clear();
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < 1000; j++)
            {
                if (mat[i][j])
                {
                    s.push_back(mat[i][j]);
                }
            }
        }
        return s;
    }
};

int main()
{
    string s = "AB";
    cout << Solution().convert(s, 1);
    return 0;
}