#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return 0;
        }
        else if (!x)
        {
            return 1;
        }
        int x1 = x;
        int count = 0;
        while (x1)
        {
            x1 = x1 / 10;
            count++;
        }
        for (int i = 0; i <= count / 2; i++)
        {
            if (x % (long long)pow(10, i + 1) / (long long)pow(10, i) != x % (long long)pow(10, count - i) / (long long)pow(10, count - i - 1))
            {
                return 0;
            }
        }
        return 1;
    }
};

int main()
{
    int x = 1234567899;
    cout << Solution().isPalindrome(x) << endl;
    return 0;
}