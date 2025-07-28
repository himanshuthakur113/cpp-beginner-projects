#include "todo_list.h" 
#include <iostream>    
#include <stdexcept>   
#include <limits>      


TodoList::TodoList() {
    
}

void TodoList::display_menu() const {
    std::cout << "Choose one operation:\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Delete Task\n";
    std::cout << "3. Display Tasks\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void TodoList::add_task() {
    std::string task_name;
    int day, month, year;

    std::cout << "Enter task name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::getline(std::cin, task_name);

    std::cout << "Enter deadline: \n";
    std::cout << "Enter day: ";
    std::cin >> day;
    std::cout << "Enter month: ";
    std::cin >> month;
    std::cout << "Enter year: ";
    std::cin >> year;

    try {
        Task new_task(task_name, day, month, year); 
        tasks.push_back(new_task);
        std::cout << "Task added successfully!\n\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Error adding task: " << e.what() << " Task not added.\n\n";
    } catch (const std::exception& e) {
        std::cout << "An unexpected error occurred: " << e.what() << ". Task not added.\n\n";
    } catch (...) {
        std::cout << "An unknown error occurred. Task not added.\n\n";
    }
}

void TodoList::delete_task() {
    if (tasks.empty()) {
        std::cout << "No tasks available to delete.\n\n";
        return;
    }
    display_tasks(); 

    int task_number;
    std::cout << "Enter task number to delete: ";
    std::cin >> task_number;

    int index = task_number - 1;
    if (index >= 0 && index < static_cast<int>(tasks.size())) {
        std::cout << "Task '" << tasks[index].get_name() << "' deleted successfully!\n\n";
        tasks.erase(tasks.begin() + index);
    } else {
        std::cout << "Invalid task number!\n\n";
    }
}

void TodoList::display_tasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n\n";
        return;
    }
    std::cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        tasks[i].display();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void TodoList::handle_choice(int choice) {
    if (choice == 1) {
        add_task();
    } else if (choice == 2) {
        delete_task();
    } else if (choice == 3) {
        display_tasks();
    } else if (choice == 4) {
    } else {
        std::cout << "Invalid choice!\n\n";
    }
}

void TodoList::run_application() {
    std::cout << "\nWelcome to the To-Do List Application!\n\n";

    while (true) {
        display_menu(); 
        int choice;
        std::cin >> choice;

        if (choice == 4) {
            std::cout << "Exiting application. Goodbye!\n" << std::endl;
            break; 
        }
        handle_choice(choice); 
    }
}
