#pragma once

#include <string>
#include <vector>

class Student
{
public:
    std::string name;
    std::string surname;
    std::vector<int> marks;
    int exam;
    double final_mark_avg;
    double final_mark_med;
    std::string category;
    bool file;

    bool compareStudentsNames(const Student& a, const Student& b);
};

