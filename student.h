#pragma once

#include <string>
#include <vector>
#include <fstream>

class Student
{
public:
    bool compareStudentsNames(const Student &a, const Student &b);

    Student(){};
    Student(std::string n, std::string s, std::vector<int> m, int e, double avg, double med, std::string c = "");

    ~Student(){};

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

    const double getFinalMarkMed()
    {
        return final_mark_med;
    };

    const std::vector<int> &getMarks()
    {
        return marks;
    }

    const std::string &getName()
    {
        return name;
    };

    const std::string &getSurname()
    {
        return surname;
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

    void setName(const std::string &n)
    {
        name = n;
    };

    void setSurname(const std::string &s)
    {
        surname = s;
    };

    void setExam(const int &e)
    {
        exam = e;
    }

private:
    std::string name;
    std::string surname;
    std::vector<int> marks;
    int exam;
    double final_mark_avg;
    double final_mark_med;
    std::string category;
};
