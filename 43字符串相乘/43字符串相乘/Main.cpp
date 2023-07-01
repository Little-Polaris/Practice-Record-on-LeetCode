#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size(), size2 = num2.size();
        int tsize = size1 + size2;
        vector<int> v(tsize + 1);
        vector<vector<int>> product(size2, vector<int>(tsize + 1));
        for (int i = size2 - 1; i >= 0; i--) {
            for (int j = size1 - 1; j >= 0; j--) {
                product[size2 - 1 - i][i + j + 2] = (num2[i] - '0') * (num1[j] - '0');
            }
        }
        for (auto it1 = product.begin(); it1 != product.end() - 1; it1++) {
            for (auto it2 = (*it1).begin(); it2 != (*it1).end(); it2++) {
                product.back()[it2 - (*it1).begin()] += *it2;
            }
        }
        int flag = 0;
        do {
            flag = 0;
            for (auto it = product.back().rbegin(); it != product.back().rend() - 1; it++) {
                if (*it >= 10) {
                    *(it + 1) += *it / 10;
                    *it = *it % 10;
                    flag = 1;
                }
            }
        } while (flag);
        string str;
        str.resize(tsize + 1);
        for (auto it = product.back().rbegin(); it != product.back().rend(); it++) {
            str[tsize - (it - product.back().rbegin())] = *it + '0';
        }
        while (str.front() == '0') {
            str.erase(str.begin());
            if (str.empty()) {
                return "0";
            }
        }
        return str;
    }
};

int main() {
    cout << Solution().multiply("99999999999999999999999999999", "9999999999") << endl;
	return 0;
}