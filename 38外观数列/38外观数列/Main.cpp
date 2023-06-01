#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
        {
            return "1";
        }
        string str = countAndSay(n - 1);
        string result;
        for (auto i = str.begin(); i != str.end(); i++)
        {
			auto j = find_if(i, str.end(), bind1st(not_equal_to<char>(), *i));
			int count = distance(i, j);
            result += to_string(count) + *i;
            i += count - 1;
		}
        return result;
    }
};

int main()
{
	Solution s;
	cout << s.countAndSay(5) << endl;
	return 0;
}