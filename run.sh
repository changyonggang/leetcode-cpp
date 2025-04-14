#!/bin/bash

cd build

# 清理当前目录下的所有文件
echo "开始清理当前目录下的所有文件..."
rm -rf *
if [ $? -ne 0 ]; then
    echo "清理文件时出现错误，脚本终止。"
    exit 1
fi
echo "文件清理完成。"

# 使用 CMake 配置项目
echo "开始使用 CMake 配置项目..."
cmake ..
if [ $? -ne 0 ]; then
    echo "CMake 配置项目时出现错误，脚本终止。"
    exit 1
fi
echo "CMake 配置项目完成。"

# 并行编译项目
echo "开始并行编译项目..."
make -j8 -v
if [ $? -ne 0 ]; then
    echo "并行编译项目时出现错误，脚本终止。"
    exit 1
fi
echo "项目编译完成。"


echo "running start ......................\n\n\n"

./leetcode-cpp


echo "\n\n\n running end ......................"
