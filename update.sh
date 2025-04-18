#!/bin/bash
set -euo pipefail

TARGET_DIR="${1:-.}"

if [ ! -d "$TARGET_DIR" ]; then
  echo "错误：目录 $TARGET_DIR 不存在"
  exit 1
fi

echo "即将递归删除以下内容："
echo "1. 所有名为 build 的目录"
echo "2. 所有名为 CMakeLists.txt 的文件"
echo "3. 所有名为 open.sh 的文件"
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
  
  echo "正在删除 open.sh 文件"
  find "$TARGET_DIR" -type f -name "open.sh" -exec rm -f {} +

  echo "正在删除 main.exe 文件..."
  find "$TARGET_DIR" -type f -name "main.exe" -exec rm -f {} +
  
  echo "正在删除 main 文件..."
  find "$TARGET_DIR" -type f -name "main" -exec rm -f {} +
  
  echo "正在删除 .main.cpp.swp..."
  find "$TARGET_DIR" -type f -name ".main.cpp.swp" -exec rm -f {} +

  python3 ./Tool/Statistics/update.py
else
  echo "操作已取消"
fi

