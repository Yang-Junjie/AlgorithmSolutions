    // #include <algorithm>
    // #include <iostream>
    // #include <string>
    // #include <utility>
    // #include <vector>
    // #include <numeric>
    // #include <limits>
    // #include <iomanip>
    // #include <cmath>
    // #include <set>
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<char>> g(n + 2, vector<char>(m + 2));
        for (int i = 0; i < n + 2; i++)
        {
            for (int j = 0; j < m + 2; j++)
            {
                g[i][j] = '#';
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> g[i][j];
            }
        }
        int ans = 0;
        // for(int i = 0;i<n+2;i++){
        //     for(int j = 0;j<m+2;j++){
        //         cout<<g[i][j];
        //     }
        //     cout<<'\n';
        // }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (g[i][j] == '.')
                {
                    int l = j;
                    int cnt = 0;
                    while (g[i][l] != '#')
                    {
                        l++;
                        cnt++;
                        if (cnt == k)
                        {
                            ans++;
                            break;
                        }
                    }
                }
                if (g[i][j] == '.')
                {
                    int l = i;
                    int cnt = 0;
                    while (g[l][j] != '#')
                    {
                        l++;
                        cnt++;
                        if (cnt == k)
                        {
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        if(k==1){
            ans/=2;
        }
        cout << ans << endl;

        return 0;
    }