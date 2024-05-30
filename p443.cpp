// STRING COMPRESSION

#include <iostream>
#include <vector>

using namespace std;

void PrintString(vector<char>& chars) {
    for (auto c : chars) {
        cout << c;
    }
    cout << endl;
}

int compress(vector<char>& chars) {
    int n = chars.size();
    int i = 0;
    while (i < n) {
        char curr = chars[i];
        int j = i + 1;
        int count = 1;

        if (j>=n) break;
        const auto it = chars.begin();

        while (chars[j]==curr && j<chars.size()) {
            chars.erase(it + j);
            count++;
        }
        
        string count_s;
        if (count != 1) {
            count_s = to_string(count);
            for(auto c : count_s) {
                chars.insert(it + j, c);
                j++;
            }
        }
        i = i + count_s.size() + 1;
        n = chars.size();
    }
    return n;
}

int main() {

    vector<char> s{'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    cout << compress(s) << endl;
}
