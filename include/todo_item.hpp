#pragma once
#include <string>

class TodoItem
{
private:
    std::string content_;
    bool done_ = false; // 預設為未完成

public:
    TodoItem(const std::string &content) : content_(content) {}
    void mark_done()
    {
        done_ = true;
    }
    std::string content() const
    {
        return content_;
    }
    bool is_done() const
    {
        return done_;
    }
};