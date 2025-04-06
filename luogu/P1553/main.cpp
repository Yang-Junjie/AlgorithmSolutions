#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void removeLeadingZeros(string& s, int start) {
    while (start < s.size() && s[start] == '0') {
        s.erase(start, 1);
    }
    if (start >= s.size()) s.insert(start, "0");
}

void removeTrailingZeros(string& s) {
    while (!s.empty() && s.back() == '0') {
        s.pop_back();
    }
    if (s.empty()) s = "0";
}

void processFractionOrDecimal(string& s, int pos) {
    string part1 = s.substr(0, pos);
    reverse(part1.begin(), part1.end());
    removeLeadingZeros(part1, 0);

    string part2 = s.substr(pos + 1);
    reverse(part2.begin(), part2.end());
    removeLeadingZeros(part2, 0);

    if (s[pos] == '.') {
        removeTrailingZeros(part2);
    }

    s = part1 + string(1, s[pos]) + part2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;

    if (s.back() == '%') {
        string num = s.substr(0, s.size() - 1);
        reverse(num.begin(), num.end());
        removeLeadingZeros(num, 0);
        cout << num << "%\n";
    } else {
        int type = -1; // 0: decimal, 1: fraction
        size_t dot = s.find('.');
        size_t slash = s.find('/');

        if (dot != string::npos) {
            processFractionOrDecimal(s, dot);
        } else if (slash != string::npos) {
            processFractionOrDecimal(s, slash);
        } else {
            reverse(s.begin(), s.end());
            removeLeadingZeros(s, 0);
        }

        cout << s << "\n";
    }

    return 0;
}
