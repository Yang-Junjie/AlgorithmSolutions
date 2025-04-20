    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <utility>
    #include <vector>
    #include <numeric>
    #include <limits>
    #include <cmath>
    #include <unordered_set>
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
                std::cout << " | " <<"\033[33m"<< *it++<< "\033[0m";
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
   
    void solve(){
        int ans = 0;
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> c1(30,0);
        vector<int> c2(30,0);
        for(int i = 0;i<n;i++){
            c1[s[i]-'a'+1]++;
        }
        for (int i = 0; i < n; i ++ )
        {
            c1[s[i] - 'a' + 1] -- ;
            c2[s[i] - 'a' + 1] ++ ;
            int s1 = 0, s2 = 0;
            for (int j = 1; j <= 26; j ++ )
            {
                if (c1[j])	s1 ++ ;
                if (c2[j])	s2 ++ ;
            }
            ans = max(ans, s1 + s2);
        }
        cout << ans << endl;
        
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int t;
        cin>>t;
        while(t--){
            solve();
        }

        return 0;
    }