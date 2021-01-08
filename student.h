#pragma once

#include "human.h"

#include <string>
#include <vector>
#include <fstream>

class Student: public Human
{
private:
    std::vector<int> marks;
    int exam;
    double final_mark_avg;
    double final_mark_med;
    std::string category;

public:
    bool compareStudentsNames(const Student &a, const Student &b);

    Student() {};
    Student(std::string n, std::string s, std::vector<int> m, int e, double avg, double med, std::string c = "") : Human{n, s}, marks{m}, exam{e}, final_mark_avg{avg}, final_mark_med{med}, category{c} {};

    ~Student() {};

    Student &operator=(const Student &that)
    {
        name = that.name;
        surname = that.surname;
        marks = that.marks;
        exam = that.exam;
        final_mark_avg = that.final_mark_avg;
        final_mark_med = that.final_mark_med;
        category = that.category;
        return *this;
    };

    Student(const Student &that)
    {
        name = that.name;
        surname = that.surname;
        marks = that.marks;
        exam = that.exam;
        final_mark_avg = that.final_mark_avg;
        final_mark_med = that.final_mark_med;
        category = that.category;
    }

    // Getters
    const double &getFinalMarkAvg()
    {
        return final_mark_avg;
    };

    const double &getFinalMarkMed()
    {
        return final_mark_med;
    };

    const std::vector<int> &getMarks()
    {
        return marks;
    }

    const std::string &getCategory()
    {
        return category;
    };

    // Setters
    void setCategory(const std::string &c)
    {
        category = c;
    };

    void setMarks(const std::vector<int> &m)
    {
        marks = m;
    };

    void setExam(const int &e)
    {
        exam = e;
    }
    void setFinalMarkAvg(const double &avg)
    {
        final_mark_avg = avg;
    }
    void setFinalMarkMed(const double &med)
    {
        final_mark_med = med;
    }
};
