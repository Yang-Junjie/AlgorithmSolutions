#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    scanf("%d %d", &n, &m);
    int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
        day[2] = 29;
    printf("%d", day[m]);

    return 0;
}
