cmake_minimum_required(VERSION 3.10)
project(TodoOOP)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含 include/ 和 tests/ 兩個目錄
include_directories(include tests)

# 主程式可執行檔
add_executable(todo
    src/main.cpp
    src/todo_list.cpp
)

# 單元測試可執行檔
add_executable(test_todo
    tests/test_todo.cpp
    src/todo_list.cpp
    tests/catch_amalgamated.cpp
)

# 如果你有額外的 source file 或 header，記得加進來

# 如需加入更多第三方庫（ex: gtest, OpenCV），也能在這裡擴充設定
