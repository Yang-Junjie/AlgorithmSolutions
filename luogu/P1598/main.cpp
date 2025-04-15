#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 4;

// 返回所有最大元素的索引
vector<int> find_max_elements(int arr[], int length) {
    vector<int> max_indices;
    int max_element = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
            max_indices.clear();
            max_indices.push_back(i);
        }
        else if (arr[i] == max_element) {
            max_indices.push_back(i);
        }
    }
    return max_indices;
}

int sum_count(int arr[], int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        count += arr[i];
    }
    return count;
}

void Solution() {
    string q[N];
    for (int i = 0; i < N; i++) {
        getline(cin, q[i]);
    }

    // for(int i = 0;i<N;i++){
    //     cout<<q[i]<<endl;
    // }
    //字母出现的次数从count[0-25]依次代表A-Z
    //A-Z对应字符码为65-90

    int count[26] = { 0 };
    for (int i = 0; i < N; i++) {
        for (char ch : q[i]) {
            for (int j = 0; j < 26; j++) {
                if (static_cast<int>(ch) == j + 65) {
                    count[j]++;
                }
            }
        }
    }
    int total = sum_count(count, 26);

    while (total > 0) {
        vector<int> max_indices = find_max_elements(count, 26);
        for (int i = 0; i < 26; i++) {
            if (std::find(max_indices.begin(), max_indices.end(), i) != max_indices.end()) {
                printf("* ");
                if (count[i] > 0) {
                    count[i]--;
                    total--;
                }
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
}

int main() {
    Solution();
    return 0;
}
