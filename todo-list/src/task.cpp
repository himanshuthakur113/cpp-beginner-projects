
#include "task.h"
#include <iostream>

Task::Task(const std::string& task_name, const Date& task_deadline)
    : name(task_name), deadline(task_deadline) {}

Task::Task(const std::string& task_name, int d, int m, int y)
    : name(task_name), deadline(d, m, y) {}

const std::string& Task::get_name() const {
    return name;
}

void Task::display() const {
    std::cout << name << " - Deadline: ";
    deadline.print_formatted();
}
