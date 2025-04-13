#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
using PII = pair<int, int>;
struct Student {
    int id = 0;
    int sum = 0;
    int ch = 0;
    int math = 0;
    int eng = 0;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Student> Students(n);
    for (int i = 0; i < n; i++) {
        Students[i].id = i + 1;
        cin >> Students[i].ch >> Students[i].math >> Students[i].eng;
        Students[i].sum = Students[i].ch + Students[i].math + Students[i].eng;
    }
    sort(Students.begin(), Students.end(), [](const Student& s1, const Student& s2) {
        if (s1.sum != s2.sum) {
            return s1.sum > s2.sum;
        } else if (s1.ch != s2.ch) {
            return s1.ch > s2.ch;
        } else {
            return s1.id < s2.id;
        }
    });
    for (int i = 0; i <= 4; i++) {
        cout << Students[i].id << " " << Students[i].sum << endl;
    }
    return 0;
}
