#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int count = 0;
        int flag = 1;
        if (dividend < 0)
        {
            dividend = -dividend;
            flag = -flag;
        }
        if (divisor < 0)
        {
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
        }
        return count;
    }
};

int main()
{
    cout << Solution().divide(-pow(2, 31), -1) << endl;
	return 0;
}