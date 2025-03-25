#!/bin/bash
set -euo pipefail

# 目标目录（默认为当前目录）
TARGET_DIR="${1:-.}"

# 检查目录是否存在
if [ ! -d "$TARGET_DIR" ]; then
  echo "错误：目录 $TARGET_DIR 不存在"
  exit 1
fi

# 安全提示
echo "即将递归删除以下内容："
echo "1. 所有名为 build 的目录"
echo "2. 所有名为 CMakeLists.txt 的文件"
echo "目标路径: $(realpath "$TARGET_DIR")"
echo "----------------------------------------"
read -p "确认删除？(y/n) " -n 1 -r
echo

if [[ $REPLY =~ ^[Yy]$ ]]; then
  # 删除操作
  echo "正在删除 build 目录..."
  find "$TARGET_DIR" -type d -name "build" -exec rm -rf {} +

  echo "正在删除 CMakeLists.txt 文件..."
  find "$TARGET_DIR" -type f -name "CMakeLists.txt" -exec rm -f {} +

  echo "----------------------------------------"
  echo "清理完成！"
else
  echo "操作已取消"
fi
