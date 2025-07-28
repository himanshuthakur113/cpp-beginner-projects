#ifndef DATE_H
#define DATE_H

#include <stdexcept>
#include <string>

struct Date {
        int day;
        int month;
        int year;

        static bool validate_date(int d,int m,int y);

        Date(int d,int m,int y);

        Date();

        void print_formatted() const;
};

#endif

