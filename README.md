# todo-app

現代 C++11/14/17/20 實作的命令列待辦清單小工具。  
支援單元測試，跨平台（Windows / macOS / Linux / WSL）。

## 專案結構

```
todo-app/
├── CMakeLists.txt
├── build.bat
├── include/
├── src/
├── tests/
├── docs/
├── .gitignore
└── README.md
```

## 目錄說明
include/：C++ 標頭檔（介面定義）

src/：主程式與功能實作

tests/：單元測試程式、Catch2 測試框架

docs/：設計說明、UML、補充說明

.gitignore：git 版本控制忽略清單



## 編譯與執行與測試
在專案的根目錄下，使用以下命令編譯專案：
```bash
python build.py
```

這個腳本會根據你的系統去執行對應的腳本。

## TODO
- [ ] 完成待辦清單的 CRUD 操作
