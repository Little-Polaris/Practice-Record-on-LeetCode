#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int max = pow(2, 31) - 1;
        if (dividend == -max - 1 && divisor == 1)
        {
            return -max - 1;
        }
        if (dividend == max && divisor == 1)
        {
            return max;
        }
        else if (dividend == max && divisor == -1)
        {
            return -max;
        }
        int count = 0;
        int flag = 1;
        int former_over_flow = 0;
        int latter_over_flow = 0;
        if (dividend < 0)
        {
            if (dividend == -max - 1)
            {
                former_over_flow = 1;
                dividend = dividend + 1;
            }                      
            dividend = -dividend;
            flag = -flag;           
        }
        if (divisor < 0)
        {
            if (divisor == -max - 1)
            {
                latter_over_flow = 1;
                divisor = divisor + 1;
            }
            divisor = -divisor;
            flag = -flag;
        }
        while (1)
        {
            dividend -= divisor;
            if (dividend < 0)
            {
                if (flag < 0)
                {
                    return -count;
                }
                else
                {
                    return count;
                }
            }
            count++;
            if (count == 1)
            {
                dividend += former_over_flow;
                divisor += latter_over_flow;
            }
            if (count == max)
            {
                return count;
            }
        }
        return count;
    }
};

int main()
{
    cout << Solution().divide(pow(2,31)-1,2) << endl;
	return 0;
}