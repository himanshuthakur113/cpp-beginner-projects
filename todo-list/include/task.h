// task.h
#ifndef TASK_H
#define TASK_H

#include <string>
#include "date.h"

class Task {
private:
    std::string name;
    Date deadline;

public:
    Task(const std::string& task_name, const Date& task_deadline);
    Task(const std::string& task_name, int d, int m, int y);

    const std::string& get_name() const;
    void display() const;
};

#endif // TASK_H
