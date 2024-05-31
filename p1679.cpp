// MAX NUMBER OF K-SUM PAIRS

#include <iostream>
#include <vector>

using namespace std;

void PrintNums(vector<int>& nums) {
    for (auto n : nums) {
        std::cout << n;
    }
    std::cout << std::endl;
}

int maxOperations(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0;
    int result = 0;
    const auto it = nums.begin();

    while (i < n - 1) {
        int j = i + 1;
        int curr = nums[i];
        if (curr > k) {
            i++;
            continue;
        }

        while (j < nums.size()) {
            if (curr + nums[j] == k) {
                result++;
                nums.erase(it + j);
                nums.erase(it + i);
                i--;
                break;
            }
            j++;
        }
        i++;
        n = nums.size();
    }
    return result;
}

int main() {

    vector<int> nums{1, 2, 3, 4};
    int k = 5;
    std::cout << maxOperations(nums, k) << std::endl;
}