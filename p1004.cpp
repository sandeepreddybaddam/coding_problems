// MAX CONSECUTIVE ONES III

#include <iostream>
#include <vector>

using namespace std;

int longestOnes(vector<int>& nums, int k) { 
    int size = nums.size();
    int max_count = 0;
    int left = 0;

    for (int right = left; right < size; right++) {
        if (nums[right] == 0) k--;

        if (k<0) {
            if (nums[left] == 0) k++;
            left++;
        } else {
            max_count = max(max_count, right-left+1);
        }
    }
    return max_count;
}

int main() {
    vector<int> nums{1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    std::cout << longestOnes(nums, k) << std::endl;

}