#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string rs;
        if (num >= 1000)
        {
            int th = num / 1000;
            rs.append(th, 'M');
            num %= 1000;
        }
        if (num >= 900)
        {
            rs.append("CM");
            num -= 900;
        }
        if (num >= 500)
        {
            rs.append("D");
            num -= 500;
        }
        if (num >= 400)
        {
            rs.append("CD");
            num -= 400;
        }
        if (num >= 100)
        {
            int hd = num / 100;
            rs.append(hd, 'C');
            num %= 100;
        }
        if (num >= 90)
        {
            rs.append("XC");
            num -= 90;
        }
        if (num >= 50)
        {
            rs.append("L");
            num -= 50;
        }
        if (num >= 40)
        {
            rs.append("XL");
            num -= 40;
        }
        if (num >= 10)
        {
            int tens = num / 10;
            rs.append(tens, 'X');
            num %= 10;
        }
        if (num >= 9)
        {
            rs.append("IX");
            num -= 9;
        }
        if (num >= 5)
        {
            rs.append("V");
            num -= 5;
        }
        if (num >= 4)
        {
            rs.append("IV");
            num -= 4;
        }
        if (num >= 1)
        {
            rs.append(num, 'I');
            num -= num;
        }
        if (num == 0)
        {
            return rs;
        }
        return rs;
    }
};

int main()
{
    int n = 1994;
    cout << Solution().intToRoman(n) << endl;
    return 0;
}