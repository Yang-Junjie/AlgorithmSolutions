

#!/bin/bash
if [ -z "$1" ]; then
    echo "Please provide a directory name!"
    exit 1
fi

TARGET_DIR=$1
shift  # 移除目录名参数，处理剩余参数

ALT_MODE=0

# 处理可选参数
while [[ $# -gt 0 ]]; do
    case "$1" in
        --cf)
            ALT_MODE=1
            shift
            ;;
        *)
            echo "Unknown option: $1"
            exit 1
            ;;
    esac
done

mkdir -p "$TARGET_DIR"

# 根据模式生成不同的 main.cpp
if [ $ALT_MODE -eq 1 ]; then
    cat <<EOL > "$TARGET_DIR/main.cpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
using PII = pair<int,int>;

void solve(){


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
EOL
else
    cat <<EOL > "$TARGET_DIR/main.cpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;
#define LOG(a) std::cout << "[" << #a << ":" << (a) << "]" << std::endl;
using i64 = long long int;
using u64 = unsigned long long int;
using u32 = unsigned int;
using PII = pair<int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    

    return 0;
}
EOL
fi

# 其余文件保持不变
cat <<EOL > "$TARGET_DIR/CMakeLists.txt"
cmake_minimum_required(VERSION 3.10.0)
project(Test)
add_executable(a main.cpp)
EOL

cat <<EOL > "$TARGET_DIR/open.sh"
termux-open main.cpp
EOL

chmod +x "$TARGET_DIR/open.sh"

mkdir -p "$TARGET_DIR/build"

cat <<EOL > "$TARGET_DIR/build/execute.sh"
#!/bin/bash
cmake .. && make && ./a
EOL

chmod +x "$TARGET_DIR/build/execute.sh"

echo "Directory created successfully!"
cd "$TARGET_DIR"



