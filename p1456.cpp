// MAXIMUM NUMBER OF VOWELS IN A SUBSTRING OF GIVEN LENGTH

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string vowels = "aeiou";

bool IsVowel(char c) {
    int found = vowels.find(c);
    return found != string::npos;
}

int maxVowels(string s, int k) {
    int n = s.size();
    int count = 0;
    for (int i=0; i<k; i++) {
        if (IsVowel(s[i])) count++;
    }
    int max_count = count;
    for (int i=k; i<n; i++) {
        char tail_char = s[i-k];
        char curr_char = s[i];

        if (IsVowel(tail_char)) count--;
        if (IsVowel(curr_char)) count++;
        max_count = std::max(max_count, count);
    }
    return max_count;
}

int main() {
    string s = "abciiidef";
    int k = 3;
    std::cout << maxVowels(s, k) << std::endl;
}