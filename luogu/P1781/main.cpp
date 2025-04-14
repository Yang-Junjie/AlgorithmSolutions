#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> votes(n);
    int max_idx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
        if (votes[i].size() > votes[max_idx].size() || 
           (votes[i].size() == votes[max_idx].size() && votes[i] > votes[max_idx])) {
            max_idx = i;
        }
    }
    cout << max_idx + 1 << endl << votes[max_idx] << endl;
    return 0;
}