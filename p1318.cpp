// MINIMUM FLIPS TO MAKE [A] OR [B] EQUALS TO [C]
#include <iostream>
#include <bitset>

int minFlips(int a, int b, int c) {
    if (c == (a | b)) return 0;

    std::bitset<32> a_bit(a);
    std::bitset<32> b_bit(b);
    std::bitset<32> c_bit(c);

    int i = a_bit.size();
    int result = 0;

    while (i--) {
        if ((a_bit[i] || b_bit[i]) == c_bit[i]) {
            continue;
        }
        if (c_bit[i] == 1) result += 1;
        if (c_bit[i] == 0) {
            if ((a_bit[i] && b_bit[i]) == 1) {
                result += 2;
            } else {
                result += 1;
            }
        }
    }
    return result;
}

int main() {
    int a = 2;
    int b = 6;
    int c = 5;
    std::cout << minFlips(a, b, c) << std::endl;
}