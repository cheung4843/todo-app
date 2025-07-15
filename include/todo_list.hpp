#pragma once
#include <vector>
#include "todo_item.hpp"

class TodoList
{
private:
  std::vector<TodoItem> items_;

public:
  void add(const std::string &content);
  void list() const;
  void mark_done(size_t idx);
  void remove(size_t idx);
  size_t size() const;
};