#!/bin/bash

# 获取当前日期和时间戳
current_time=$(date "+%Y-%m-%d %H:%M:%S")
current_date=$(date "+%Y-%m-%d")

# 统计总文件数（排除.git和.vscode目录）
total_count=$(find . -type f -name "main.cpp" -not -path "./.git/*" -not -path "./.vscode/*" | wc -l)

# 统计各子目录文件数（排除.git和.vscode目录）
subdir_stats=""
while IFS= read -r dir; do
    dir_name=${dir#./}  # 去除路径前的./
    count=$(find "$dir" -type f -name "main.cpp" -not -path "./.git/*" -not -path "./.vscode/*" | wc -l)
    subdir_stats+="${dir_name}: ${count}, "
done < <(find . -maxdepth 1 -type d ! -path . ! -path './.git' ! -path './.vscode')

# 构建输出内容（确保单行）
output="${current_time}: 发现 ${total_count} 个main.cpp文件"
if [ -n "$subdir_stats" ]; then
    subdir_stats=${subdir_stats%, }  # 去除末尾的逗号和空格
    output+="目录分布：${subdir_stats}"
fi

# 处理README.md（覆盖当日旧记录，只保留当天最后一次结果）
if [ -f "README.md" ]; then
    # 删除当日所有旧记录（基于日期开头）
    grep -v "^${current_date}" README.md > temp.md
    mv temp.md README.md
fi
# 写入新记录到README.md（单行）
echo "$output" >> README.md

# 处理diary.md（保留所有日期的最后一次记录）
if [ -f "diary.md" ]; then
    # 删除当日所有旧记录（基于日期开头）
    grep -v "^${current_date}" diary.md > temp_diary.md
    mv temp_diary.md diary.md
fi
# 追加新记录到diary.md（单行）
echo "$output" >> diary.md

# 输出确认信息
echo "📊统计完成！当日结果已更新至 README.md，历史记录已保存至 diary.md"

