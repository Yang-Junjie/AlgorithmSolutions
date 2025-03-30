#!/bin/bash

# 启用nullglob选项，当没有匹配时返回空
shopt -s nullglob

# 检查crate.sh是否存在
if [ ! -f "crate.sh" ]; then
    echo "错误：crate.sh 文件未在当前目录中找到。" >&2
    exit 1
fi

# 遍历所有一级子目录并复制文件
for dir in */; do
    cp "crate.sh" "${dir}"
    echo "已复制到：${dir}"
done

# 恢复nullglob选项（可选）
shopt -u nullglob
