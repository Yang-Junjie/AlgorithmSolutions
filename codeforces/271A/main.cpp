#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string y;

int main()
{
    cin >> y;
    while (1) {
        bool finded = false;
        y = to_string(stoi(y) + 1);
        for (int i = 0; i < y.size() - 1; i++) {
            for (int j = i + 1; j < y.size(); j++) {
                if (y[i] == y[j]) {
                    finded = true;
                }
            }
        }
        if (!finded) {
            cout << y;
            break;
        }
    }
    return 0;
}
