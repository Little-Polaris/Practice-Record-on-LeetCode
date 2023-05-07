#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int graph[51][51] = { 0 };
        for (int i = 1; i < values.size(); i++)
        {
            graph[i][i + 1] = values[i - 1] * values[i];
        }
        graph[values.size()][1] = values[0] * values[values.size() - 1];
        int a = 0;
        return 0;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int>v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cout << Solution().minScoreTriangulation(v) << endl;
}