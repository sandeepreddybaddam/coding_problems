// LETTER COMBINATIONS OF A PHONE NUMBER
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void PrintLetterCombinations(vector<string> strings) {
    std::cout << "[";
    for (const auto s : strings) {
        std::cout << s << ", ";
    }
    std::cout << "]" << std::endl;
}

unordered_map<int, string> GetLetters() {
    unordered_map<int, string> result;
    result[2] = "abc";
    result[3] = "def";
    result[4] = "ghi";
    result[5] = "jkl";
    result[6] = "mno";
    result[7] = "pqrs";
    result[8] = "tuv";
    result[9] = "wxyz";

    return result;
}

void recursion(string digits, string& curr, vector<string>& ans, int len) {
    if (digits.size() == 0) return;
    int num = digits[0] - '0';
    string phone_letters = GetLetters()[num];

    for (const auto& letter : phone_letters) {
        string curr_ = curr;
        curr += letter;
        recursion(digits.substr(1), curr, ans, len);
        if (curr.size() == len) ans.push_back(curr);
        curr = curr_;
    }
    return;
}

vector<string> letterCombinations(string digits) {
    vector<string> ans{};
    string curr;
    recursion(digits, curr, ans, digits.size());
    return ans;
}

int main() {
    string digits{"23"};
    const auto result = letterCombinations(digits);
    PrintLetterCombinations(result);
}