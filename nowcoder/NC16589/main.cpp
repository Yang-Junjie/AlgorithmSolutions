#include <iostream>
using namespace std;

const int N = 110;
int q[N], ans = 0;

int main() {
    int m, n, size = 0; // size记录当前内存中的单词数
    cin >> m >> n;
    
    while (n--) {
        int a;
        cin >> a;
        bool found = false;
        
        // 检查单词是否在内存中，只检查前size个有效元素
        for (int i = 1; i <= size; ++i) {
            if (q[i] == a) {
                found = true;
                break;
            }
        }
        
        if (!found) {
            ++ans;
            if (size < m) { // 内存未满，直接加入队尾
                ++size;
                q[size] = a;
            } else { // 内存已满，移除队头后加入队尾
                // 所有元素前移一位（模拟队列出队）
                for (int i = 1; i < m; ++i) {
                    q[i] = q[i + 1];
                }
                q[m] = a; // 新元素加到队尾
            }
        }
    }
    
    cout << ans;
    return 0;
}

