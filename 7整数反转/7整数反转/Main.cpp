#include <iostream>
#include <string>
#include <algorithm>


class Solution {
public:
    int reverse(int x) {
        if (!x)
        {
            return x;
        }
        int x1 = x;
        int x2;
        if (x >= 0)
        {
            x2 = x;
        }
        else
        {
            x2 = -x;
        }
        if (x2 < 0)
        {
            return 0;
        }
        int count = 0;
        while (x1)
        {
            x1 /= 10;
            count++;
        }
        char* s = new char[count + 1];
        snprintf(s, count + 1, "%d", x2);
        std::string re_s(s);
        delete[] s;
        std::reverse(re_s.begin(), re_s.end());
        try
        {
            x1 = std::stoi(re_s);
        }
        catch (...)
        {
            return 0;
        }
        x1 = x > 0 ? x1 : -x1;
        return x1;
    }
};

int main()
{
    int x = -2147483648;
    std::cout << Solution().reverse(x) << std::endl;
    return 0;
}