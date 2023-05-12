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
        if (divisor == -pow(2, 31))
        {
            return 0;
        }
        else if (dividend == -divisor)
        {
            return -1;
        }
        if (divisor == 1)
        {
            return dividend;
        }
        else if (divisor == -1)
        {
            if (dividend == -pow(2, 31))
            {
                return pow(2, 31) - 1;
            }
            else
            {
                return -dividend;
            }
        }
        int flag = 1;
        if (dividend == -pow(2, 31))
        {
            if (divisor == -1)
            {
                return pow(2, 31) - 1;
            }
            else if (divisor == 1)
            {
                return dividend;
            }
            else if (divisor == -2)
            {
                return pow(2, 30);
            }
            else if (divisor == 2)
            {
                return -pow(2, 30);
            }
            else
            {
                for (int i = 1; i < 31; i++)
                {
                    if (divisor == pow(2, i))
                    {
                        return -pow(2, 31 - i);
                    }
                }
            }
            dividend = pow(2, 31) - 1;
            flag = -flag;   
        }
        else if (dividend < 0)
        {
            dividend = -dividend;
            flag = -flag;
        } 
        if (divisor < 0)
        {
            divisor = -divisor;
            flag = -flag;
        }
        int small = divisor;
        int max = pow(2, 31) - 1;
        int big;
        if (max - divisor < divisor)
        {
            big = max;
        }
        else
        {
            big = divisor + divisor;
        }
        int flag1 = 0;
        int count = 0;
        while (dividend >= big && max - big > big)        
        {
            flag1 = 1;
            small += small;
            big += big;
            count++;
        }
        if (flag1 || dividend >= divisor)
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
    cout << Solution().divide(-pow(2,31), 8) << endl;
	return 0;
}