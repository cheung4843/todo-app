#include <iostream>
#include <string>
#include <limits>
#include "todo_list.hpp"

int main()
{
    TodoList todos;
    while (true)
    {
        std::cout << "\n1. List  2. Add  3. Mark Done  4. Delete  5. Exit\n";
        std::cout << "Choose an option: ";
        int choice;
        if (!(std::cin >> choice))
        { // 如果讀取失敗（非數字）
            if (std::cin.eof())
                break; // Ctrl+Z 也能離開
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number 1-5.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            todos.list();
            break;
        case 2:
        {
            std::cout << "Enter new todo: ";
            std::string s;
            std::getline(std::cin, s);
            todos.add(s);
            break;
        }
        case 3:
        {
            std::cout << "Index to mark done: ";
            int idx;
            if (std::cin >> idx)
                todos.mark_done(idx);
            break;
        }
        case 4:
        {
            std::cout << "Index to delete: ";
            int idx;
            if (std::cin >> idx)
                todos.remove(idx);
            break;
        }
        case 5:
            return 0; // 正常離開
        default:
            std::cout << "Invalid option. Please choose 1-5.\n";
        }
    }
    return 0;
}
