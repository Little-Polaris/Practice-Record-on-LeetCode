#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!dividend)
        {
            return 0;
        }
        if (dividend == divisor)
        {
            return 1;
        }
        int flag = 1;
        if (dividend == -pow(2, 31))
        {
            ;
        }
        else if (dividend < 0)
        {
            dividend = -dividend;
            flag = -flag;
        }
        if (divisor == -pow(2, 31))
        {
            ;
        }
        else if (divisor < 0)
        {
            divisor = -divisor;
            flag = flag;
        }
        int small = divisor;
        int big = divisor + divisor;
        int max = pow(2, 31) - 1;
        int flag1 = 0;
        int count = 0;
        while (dividend >= big && max - big > big)        
        {
            flag1 = 1;
            small += small;
            big += big;
            count++;
        }
        if (flag1)
        {
            count = pow(2, count);
        }
        while (small <= dividend - divisor && max - small > divisor)
        {
            small += divisor;
            count++;
        }
        if (flag == -1)
        {
            return -count;
        }
        else
        {
            return count;
        }
    }
};

int main()
{
    cout << Solution().divide(pow(2,31) - 1, 2) << endl;
	return 0;
}