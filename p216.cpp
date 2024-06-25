// COMBINATION SUM III
#include <iostream>
#include <vector>

using namespace std;

void PrintResult(const vector<vector<int>>& matrix) {
    std::cout << "[";
    for (const auto& row : matrix) {
        std::cout << "[";
        for (const auto& element : row) {
            std::cout << element << ", ";
        }
        std::cout << "]";
    }
    std::cout << "]" << std::endl;
}

void PrintSubResult(const vector<int>& row_matrix) {
    std::cout << "[";
    for (const auto& element : row_matrix) {
        std::cout << element << ", ";
    }
    std::cout << "]" << std::endl;
}

void recursion(int k, int n, vector<vector<int>>& result, vector<int>& sub_result, int s) {
    if (n == 0 && k == 0) {
        result.push_back(sub_result);
    }
    if (n < 0 || k == 0) return;

    for (int i = s + 1; i <= 9; i++) {
        sub_result.push_back(i);
        recursion(k-1, n-i, result, sub_result, i);
        sub_result.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> sub_result{};
    int s = 0;
    recursion(k, n, result, sub_result, s);
    return result;
}

int main() {
    int k = 3;
    int n = 7;
    const auto result = combinationSum3(k, n);
    PrintResult(result);
}