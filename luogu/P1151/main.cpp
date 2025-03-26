#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int k;
string num;
string rmBeforeZero(const string& str)
{
    int i = 0;
    while (str[i] == '0' && i < str.size())
        i++;
    if (i == str.size())
        return "0";
    return str.substr(i);
}
int ans_cnt = 0;
int main()
{
    cin >> k;
    for (int i = 10000; i <= 30000; i++) {
        num = to_string(i);

        bool isAns = 1;
        for (int j = 0; j <= num.size() - 3; j++) {
            string str1 = num.substr(j, 3);
            str1 = rmBeforeZero(str1);
            if (stoi(str1) % k != 0) {
                isAns = false;
            }
        }
        if (isAns) {
            ans_cnt++;
            cout << num << endl;
        }
    }
    if (ans_cnt == 0) {
        cout << "No" << endl;
    }
    return 0;
}
