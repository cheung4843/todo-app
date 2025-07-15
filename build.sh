#!/bin/bash

# chmod +x build.sh
# 設定腳本遇到錯誤就中斷
set -e

# 建立 build 目錄
if [ ! -d build ]; then
    mkdir build
fi

cd build

# 重新用 cmake 編譯
cmake ..
make -j

cd ..

echo ""
read -p "要執行單元測試（test_todo）嗎？ [y/N]: " RUN_TEST
if [[ "$RUN_TEST" =~ ^[Yy]$ ]]; then
    echo "執行單元測試..."
    ./build/test_todo
    echo ""
fi

read -p "要執行主程式（todo）嗎？ [y/N]: " RUN_TODO
if [[ "$RUN_TODO" =~ ^[Yy]$ ]]; then
    echo "執行主程式..."
    ./build/todo
    echo ""
fi
