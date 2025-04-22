    // #include <algorithm>
    // #include <iostream>
    // #include <string>
    // #include <utility>
    // #include <vector>
    // #include <numeric>
    // #include <limits>
    // #include <cmath>
    // #include <iomanip>
    #include <bits/stdc++.h>
    using namespace std;

    #ifdef DEBUG
    template <typename Container>
    void PrintCon(const Container &cont)
    {
        std::cout << "{ ";
        if (!cont.empty())
        {
            auto it = cont.begin();
            std::cout << "\033[33m" << *it++ << "\033[0m";
            for (; it != cont.end(); ++it)
                std::cout << " | " << "\033[33m" << *it << "\033[0m";
        }
        std::cout << " }" << std::endl;
    }

    template <typename... Args>
    void LOG(Args &&...values)
    {
        ((std::cout << "\033[33m" << std::forward<Args>(values) << "\033[0m" << " "), ...);
        std::cout << std::endl;
    }
    #else
    template <typename... Args>
    void LOG(Args &...args);

    template <typename Container>
    void PrintCon(const Container &cont);
    #endif

    #define LEN(a) ((int)(a).size())
    #define ALL(x) (x).begin(), (x).end()
    using ll = long long int;
    using ull = unsigned long long int;
    using PII = pair<int, int>;
    using VI = vector<int>;

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        int cnteven = 0;
        int cntodd = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] & 1)
            {
                cntodd++;
            }
            else
            {
                cnteven++;
            }
        }

        if (cntodd == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] & 1)
                {
                    cout << i + 1 << endl;
                }
            }
        }
        if (cnteven == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i]%2==0)
                {
                    cout << i + 1 << endl;
                }
            }
        }

        return 0;
    }