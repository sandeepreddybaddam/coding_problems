#include <iostream>
#include <vector>

using namespace std;


// LINEAR SEARCH
// int findPeakElement(vector<int>& nums) {
//     int size = nums.size();

//     for (int i = 0; i < size; i++) {
//         const auto is_left_smaller = [&](int left, int current) {
//             if (left < 0) return true;
//             return (nums[left] < nums[current]);
//         };
//         const auto is_right_smaller = [&](int current, int right) {
//             if (right >= size) return true;
//             return (nums[current] > nums[right]);
//         };
        
//         if (is_left_smaller(i-1, i) && is_right_smaller(i, i+1)) {
//             return i;
//         }
//     }
//     return 0;
// }

// BINARY SEARCH
int findPeakElement(vector<int>& nums) {
    int size = nums.size();
    int left = 0;
    int right = size - 1;
    
    const auto is_left_greater = [&](int left, int current) {
        if (left < 0) return false;
        return (nums[left] > nums[current]);
    };
    const auto is_right_greater = [&](int current, int right) {
        if (right >= size) return false;
        return (nums[current] < nums[right]);
    };

    while (left <= right) {
        int m = left + (right-left) / 2;
        if (is_right_greater(m, m+1)) {
            left = m+1;
        }
        else if (is_left_greater(m-1, m)) {
            right = m-1;
        }
        else {
            return m;
        }
    }
    return 0;
}

int main() {
    vector<int> nums{1, 2, 3, 1};
    std::cout << findPeakElement(nums) << std::endl;
}