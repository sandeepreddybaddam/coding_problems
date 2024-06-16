// KOKO EATING BANANAS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int max_speed_to_consider = *std::max_element(piles.begin(), piles.end());

    int left = 1;
    int right = max_speed_to_consider;
    int result = left;

    const auto can_complete_bananas = [&piles, &h](int middle) {
        unsigned long long int required_hours = 0;
        for (const auto& pile : piles) {
            required_hours += 1 + (pile - 1) / middle;
        }
        return required_hours <= h;
    };

    while (left <= right) {
        int middle = left + (right-left) / 2;
        if (can_complete_bananas(middle)) {
            result = middle;
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return result;
}

int main() {
    vector<int> piles{3,6,7,11};
    int h = 8;
    std::cout << minEatingSpeed(piles, h) << std::endl;
}