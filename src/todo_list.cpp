#include "todo_list.hpp"
#include <iostream>

void TodoList::add(const std::string &content)
{
    items_.emplace_back(content);
}

void TodoList::list() const
{
    if (items_.empty())
    {
        std::cout << "No todo items.\n";
        return;
    }
    size_t idx = 1;
    for (const auto &todo : items_)
    {
        std::cout << idx++ << ". " << (todo.is_done() ? "[X]" : "[ ]") << todo.content() << '\n';
    }
}

void TodoList::mark_done(size_t idx)
{
    if (idx > 0 and idx <= items_.size())
        items_[idx - 1].mark_done();
    else
        std::cout << "Invalid index\n";
}

void TodoList::remove(size_t idx)
{
    if (items_.empty())
    {
        std::cout << "No items to remove.\n";
        return;
    }
    if (idx > 0 and idx <= items_.size())
        items_.erase(items_.begin() + (idx - 1));
    else
        std::cout << "Invalid index\n";
}

size_t TodoList::size() const
{
    return items_.size();
}