#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int k, q;
    cin >> k >> q;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }
    
    vector<int> result;
    for (int n : queries) {
        list<int> players;
        for (int i = 1; i <= n; ++i) {
            players.push_back(i);
        }
        
        while (true) {
            vector<int> to_remove;
            for (int pos : a) {
                if (pos <= players.size()) {
                    to_remove.push_back(pos);
                }
            }
            if (to_remove.empty()) {
                break;
            }
            // Remove duplicates and sort in descending order to avoid index shifting
            sort(to_remove.begin(), to_remove.end());
            to_remove.erase(unique(to_remove.begin(), to_remove.end()), to_remove.end());
            reverse(to_remove.begin(), to_remove.end());
            
            for (int pos : to_remove) {
                auto it = players.begin();
                advance(it, pos - 1);
                players.erase(it);
            }
        }
        result.push_back(players.size());
    }
    
    for (int i = 0; i < q; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

