#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;


#ifdef DEBUG
#define LOG1(a) cerr << "[" << #a << ":" << (a) << "]" << endl
#define LOG2(a,b) cerr << "[" << #a << ":" << (a) <<","<< #b << ":" << (b) << "]" << endl
template<typename Container>
void PrintCon(const Container& cont) {
    std::cout << "{ ";
    if (!cont.empty()) {
        auto it = cont.begin(); 
        std::cout <<"\033[33m"<< *it++<< "\033[0m";
        for (; it != cont.end(); ++it)
            std::cout << " | " << *it;
    }
    std::cout << " }" << std::endl;
}

#else
#define LOG(a)
#endif

#define LEN(a) ((int)(a).size())
#define ALL(x) (x).begin(), (x).end()
using ll = long long int;
using ull = unsigned long long int;
using PII = pair<int,int>;
using VI = vector<int>;
const int N = 1e5 + 10;
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool is_add = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            is_add = false;
        }
    }
    bool is_sub = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            is_sub = false;
        }
    }
    if (is_add || is_sub) {
        cout << -1 << endl;
        return 0;
    }
    int i;
    for (i = 2; i < n-1; ++i) {
        if (a[i] < a[i - 1]) {
            break;
        }
    }

    int target = a[i-2];
    int prev = a[i - 1];
    int min_val = -1;
    int pos = -1;
    for (int j = i ; j < n-1; ++j) {
        if (a[j] > target && a[j] < prev) {
            if (a[j] < min_val) {
                min_val = a[j];
                pos = j;
            }
            
        }
    }

    if (pos != -1) 
    swap(a[i - 1], a[pos]);
    if (i - 2 >= 0) {
        swap(a[i - 1], a[i - 2]);
    }


    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    

    return 0;
}