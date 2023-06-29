#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//    int trap(vector<int>& height) {
//        if (height.size() < 3) {
//            return 0;
//        }
//        int water = 0;
//        vector<int>::iterator max1, max2;
//        if (*height.begin() >= *(height.begin() + 1)) {
//            max1 = height.begin();
//            max2 = height.begin() + 1;
//        }
//        else {
//            max1 = height.begin() + 1;
//            max2 = height.begin();
//        }
//        for (auto it = height.begin() + 2; it != height.end(); it++) {
//            if (*it > *max1) {
//                max2 = max1;
//                max1 = it;
//            }
//            else if(*it >= *max2) {
//                max2 = it;
//            }
//        }
//        if (max1 - max2 == 1 && max2 == height.begin()) {
//            *max2 = *(max1 + 1);
//            for (auto it = max1 + 1; it != height.end(); it++) {
//                if (*it > *max1) {
//                    max2 = max1;
//                    max1 = it;
//                }
//                else if (*it > *max2) {
//                    max2 = it;
//                }
//            }
//        }
//        if (max1 == height.begin() && max2 == height.end() - 1) {
//            for (auto& i : height) {
//                water += *max2 - i;
//            }
//            water += (*max1 - *max2);
//        }
//        else if (max1 == height.end() - 1 && max2 == height.begin()) {
//            for (auto& i : height) {
//                water += *max2 - i;
//            }
//            water += (*max1 - *max2);
//        }
//        else if (max1 == height.begin() || max1 == height.end() - 1) {
//            auto temp_vector1 = vector<int>(height.begin(), max2 + 1);
//            auto temp_vector2 = vector<int>(max2, height.end());
//            water += trap(temp_vector1);
//            water += trap(temp_vector2);
//        }
//        else if (max2 == height.begin() || max2 == height.end() - 1) {
//            auto temp_vector1 = vector<int>(height.begin(), max1 + 1);
//            auto temp_vector2 = vector<int>(max1, height.end());
//            water += trap(temp_vector1);
//            water += trap(temp_vector2);
//        }
//        else if (max1 > max2) {
//            auto temp_vector1 = vector<int>(height.begin(), max2 + 1);
//            auto temp_vector2 = vector<int>(max2, max1 + 1);
//            auto temp_vector3 = vector<int>(max1, height.end());
//            water += trap(temp_vector1);
//            water += trap(temp_vector2);
//            water += trap(temp_vector3);
//        }
//        else {
//            auto temp_vector1 = vector<int>(height.begin(), max1 + 1);
//            auto temp_vector2 = vector<int>(max1, max2 + 1);
//            auto temp_vector3 = vector<int>(max2, height.end());
//            water += trap(temp_vector1);
//            water += trap(temp_vector2);
//            water += trap(temp_vector3);
//        }
//        return water;
//    }
//};

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max;
        vector<int> right_max;
        left_max.reserve(height.size());
        right_max.resize(height.size());
        int max = 0;
        for (auto& i : height) {
            if (i > max) {
                max = i;
            }
            left_max.emplace_back(max);
        }
        max = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            if (height[i] > max) {
                max = height[i];
            }
            right_max[i] = max;
        }
        int water = 0;
        for (int i = 0; i < height.size(); i++) {
            int min = std::min(left_max[i], right_max[i]);
            if (height[i] < min) {
                water += (min - height[i]);
            }
        }
        return water;
    }
};

int main() {
    vector<int> v = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << Solution().trap(v) << endl;
    return 0;
}