#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double rev = 0;
        if (x == 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }
        if (n < 0)
        {
            if (n == -pow(2, 31))
            {
                n = pow(2, 31) - 1;
                x = 1 / x;
                if (x < 0)
                {
                    x = -x;
                }
            }
            else
            {
                n = -n;
                x = 1 / x;
            }
        }
        if (n == 1)
        {
            return x;
        }
        if (n % 2)
        {
            rev = myPow(x, (n - 1) / 2);
            rev *= rev;
            rev *= x;
            return rev;
        }
        else
        {
            rev = myPow(x, n / 2);
            rev *= rev;
            return rev;
        }
    }
};

int main()
{
    cout << Solution().myPow(-1, -pow(2,31)) << endl;
    return 0;
}