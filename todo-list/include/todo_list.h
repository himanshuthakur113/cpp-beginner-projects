#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <vector>
#include <string>
#include "task.h"

class TodoList {
    private:
        std::vector<Task> tasks;

        void display_menu() const;
        void handle_choice(int choice);

    public:

        TodoList();

        void add_task();
        void delete_task();
        void display_tasks() const;

        void run_application();
};

#endif
