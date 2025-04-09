#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    
    for (int i = 0; i < a.size() - 1; i++) {  
        a[i] = abs(a[i] - a[i + 1]);
    }
    a.pop_back(); 

    sort(a.begin(), a.end());
    
    bool is_jolly = true;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != i + 1) {
            is_jolly = false;
            break;
        }
    }
    
    cout << (is_jolly ? "Jolly" : "Not jolly") << endl;
    return 0;
}

