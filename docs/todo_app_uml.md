# Todo App 專案 UML 圖

```mermaid
classDiagram

class TodoItem {
  - content_: std::string
  - done_: bool
  +TodoItem(const std::string& content)
  +mark_done(): void
  +is_done(): bool
  +get_content(): const std::string&
}

class TodoList {
  - items_: std::vector<TodoItem>
  +add(const std::string& content): void
  +remove(size_t index): void
  +mark_done(size_t index): void
  +list(): void
}

class MainApp {
  +main(): int
}

MainApp --> TodoList
TodoList --> TodoItem
```

---

## 圖說

* `MainApp` 代表 `main.cpp` 的程式入口，與 `TodoList` 溝通。
* `TodoList` 管理多個 `TodoItem`，提供新增、刪除、列出、標記完成的功能。
* `TodoItem` 是待辦事項的資料結構，包含內容與是否完成。

> 本 UML 圖可作為專案結構導覽圖，未來若擴充 GUI、資料儲存，可持續補充。
