#include "date.h"
#include <iostream>

bool Date::validate_date(int d, int m, int y) {
    if (y < 1900 || y > 2100) return false;
    if (m < 1 || m > 12) return false;
    int days_in_month;
    if (m == 2) {
        if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0))
            days_in_month = 29;
        else
            days_in_month = 28;
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        days_in_month = 30;
    } else {
        days_in_month = 31;
    }
    return d >= 1 && d <= days_in_month;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    if (!validate_date(d, m, y)) {
        throw std::invalid_argument("Invalid date: " +
                                     std::to_string(d) + "-" +
                                     std::to_string(m) + "-" +
                                     std::to_string(y) + ". Year must be 1900-2100.");
    }
}
Date::Date() : day(1), month(1), year(2000) {}

void Date::print_formatted() const {
    std::cout << (day < 10 ? "0" : "") << day << "-"
              << (month < 10 ? "0" : "") << month << "-"
              << year;
}
