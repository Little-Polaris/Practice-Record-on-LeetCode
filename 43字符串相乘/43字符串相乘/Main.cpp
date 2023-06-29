#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        long long n1 = 0, n2 = 0;
        for (auto& i : num1) {
            n1 = n1 * 10 + i - '0';
        }
        for (auto& i : num2) {
            n2 = n2 * 10 + i - '0';
        }
        if (n1 == 0 || n2 == 0) {
            return "0";
        }     
        long long n11 = n1, n22 = n2;
        int count1 = 0, count2 = 0;
        while (n11) {
            n11 /= 10;
            count1++;
        }
        while (n22) {
            n22 /= 10;
            count2++;
        }
        vector<vector<int>> outer_v;
        vector<int> temp(count1 + count2 + 1);
        outer_v.assign(count2, temp);
        for (int i = count2 - 1; i >= 0; i--) {
            long long tempValue = n1 * (num2[i] - '0');
            for (int j = count1 + i + 1;  j >= 0 && tempValue; j--) {
                outer_v[i][j] = tempValue % 10;
                tempValue /= 10;
            }
        }
        vector<int> v(count1 + count2 + 1);
        for (int i = 0; i < count1 + count2 + 1; i++) {
            for (int j = 0; j < count2; j++) {
                v[i] += outer_v[j][i];
            }
        }
        for (int i = count1 + count2; i >= 0; i--) {
            if (v[i] >= 10) {
                v[i - 1] += v[i] / 10;
                v[i] %= 10;
            }
        }
        string str;
        str.resize(count1 + count2 + 1);
        for (int i = 0; i < count1 + count2 + 1; i++) {
            str[i] = v[i] + '0';
        }
        while (str.front() == '0') {
            str.erase(str.begin());
        }
        return str;
    }
};

int main() {
    cout << Solution().multiply("999", "999") << endl;
	return 0;
}