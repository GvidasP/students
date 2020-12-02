#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student
{
    std::string name;
    std::string surname;
    std::vector<int> marks;
    int exam;
    double final_mark_avg;
    double final_mark_med;
    std::string category;
    bool file;
};

#endif
