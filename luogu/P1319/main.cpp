#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }
    int current = 0;
    int cnt = 0;
    for (int num : nums) {
        for (int i = 0; i < num; ++i) {
            if (cnt == n) {
                cout << '\n';
                cnt = 0;
            }
            cout << current;
            cnt++;
        }
        current = 1 - current;
    }
    if (cnt > 0) {
        cout << '\n';
    }
    return 0;
}

