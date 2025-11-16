#pragma once
#include <fstream>
#include <unordered_map>

struct date {
    int day;
    int month;
    int year;
};

std::unordered_map<int, std::string> week = {
    {0, "Monday"},
    {1, "Tuesday"},
    {2, "Wednesday"},
    {3, "Thursday"},
    {4, "Friday"},
    {5, "Saturday"},
    {6, "Sunday"}
};

std::unordered_map<int, std::string> month = {
    {1, "JAN"},
    {2, "FEB"},
    {3, "MAR"},
    {4, "APR"},
    {5, "MAY"},
    {6, "JUN"},
    {7, "JUL"},
    {8, "AUG"},
    {9, "SEP"},
    {10, "OCT"},
    {11, "NOV"},
    {12, "DEC"}
};

date day_in(date d);

void day_out(date d);

date tomorrow(date d);

date yesterday(date d);

date increase_day(date d, int n);

date decrease_day(date d, int n);

int compute(date d);

int compute_70(date d);

int compute_day(date a, date b);

std::string checkWeekday(date d);

date later_date(date a, date b);

date input_date(std::ifstream &file);

void outputDateWihFormat(std::ofstream &file, date d, int choice);