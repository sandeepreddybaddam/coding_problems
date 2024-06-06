// LONGEST SUBARRAY OF 1'S AFTER DELETING ONE ELEMENT

#include <iostream>
#include <vector>

using namespace std;

int longestSubarray(vector<int>& nums) {
    int size = nums.size();
    int max_count = 0;
    int k = 1;

    int left = 0;

    for(int right = left; right < size; right++) {
        if (nums[right] == 0) k--;

        if (k<0) {
            if (nums[left] == 0) k++;
            left++;
        } else {
            max_count = max(max_count, right-left);
        }
    }
    return max_count;
}

int main() {
    vector<int> nums{1,1,0,1};
    std::cout << longestSubarray(nums) << std::endl;
}