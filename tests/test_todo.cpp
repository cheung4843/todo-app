#define CATCH_CONFIG_MAIN // 讓 Catch2 自動產生 main()
#include "catch_amalgamated.hpp"
#include "todo_list.hpp"

TEST_CASE("Todo List add and size", "[todo]")
{
    TodoList todos;
    REQUIRE(todos.size() == 0);

    todos.add("Buy milk");
    REQUIRE(todos.size() == 1);

    todos.add("Finish homework");
    REQUIRE(todos.size() == 2);
}

TEST_CASE("Mark done", "[todo]")
{
    TodoList todos;
    todos.add("Sleep");
    todos.mark_done(1);
    REQUIRE(todos.size() == 1);
}

TEST_CASE("Remove", "[todo]")
{
    TodoList todos;
    todos.add("Meeting");
    todos.remove(1);
    todos.add("Hang out with my cute gf Zoe!");
    REQUIRE(todos.size() == 1);
}

TEST_CASE("List items", "[todo]")
{
    TodoItem item1("Read book");
    REQUIRE_FALSE(item1.is_done());
    item1.mark_done();
    REQUIRE(item1.is_done());
    REQUIRE(item1.content() == "Read book");
}
