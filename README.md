# Todo App

A simple command-line Todo list manager written in modern C++.

## Features

- Add, list, mark, and delete tasks
- Command-line interface
- Unit-tested with Catch2
- Cross-platform build via CMake
- CI/CD automated with GitHub Actions

## Build

### Prerequisites

- CMake >= 3.16
- g++ >= 11 / clang++ / MSVC (with C++20 support)

### Instructions

```bash
# Clone the project
git clone https://github.com/your-username/todo-app.git
cd todo-app

# Build on Unix/macOS
bash build.sh

# Or on Windows
build.ps1

# Alternatively, run platform-detecting build script
python build.py
```

## Run

```bash
./build/todo
```

## Test

```bash
./build/test_todo
```

## Folder Structure

```
todo-app/
├── build/             # Build output (gitignored)
├── docs/              # Documentation (e.g. UML)
├── include/           # Header files
│   └── todo_list.hpp
├── src/               # Implementation
│   ├── main.cpp
│   └── todo_list.cpp
├── tests/             # Unit tests
│   └── test_todo.cpp
├── .github/workflows/ # GitHub Actions workflows
├── CMakeLists.txt     # CMake configuration
├── build.sh           # Unix build script
├── build.bat          # Windows build script
├── build.py           # Cross-platform build launcher
└── README.md          # Project overview
```

📘 [View UML Diagram](docs/todo_app_uml.md)

## License

MIT

---

🛠️ Built for learning modern C++ project structure, CMake, CI/CD, and clean architecture.



