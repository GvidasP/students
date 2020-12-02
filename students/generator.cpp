#include "student.h"
#include "helper.h"

#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <random>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <sstream>

std::vector<int> generateRandomMarks(int number, std::mt19937& mt)
{
    std::vector<int> marks(number);

    std::uniform_int_distribution<int> dist{ 1, 10 };

    std::generate(marks.begin(), marks.end(), [&]() { return dist(mt); });

    return marks;
}

int sumOfMarks(std::vector<int> marks)
{
    int sum_of_marks{};

    for (auto& i : marks)
        sum_of_marks += i;

    return sum_of_marks;
}

double calculateAvg(std::vector<int> marks, int exam)
{
    return 0.4 * (sumOfMarks(marks) / marks.size()) + 0.6 * exam;
}

double calculateMedian(std::vector<int> marks, int exam)
{
    return 0.4 * median(marks) + 0.6 * exam;
}

std::vector<Student> generateStudents(int amount)
{
    auto start = std::chrono::steady_clock::now();

    std::vector<Student> students;

    std::random_device rd;
    std::mt19937 mt(rd());

    for (int i = 0; i < amount; i++) {
        Student student;

        student.name = "Vardas" + std::to_string(i);
        student.surname = "Pavarde" + std::to_string(i);
        student.marks = generateRandomMarks(13, mt);
        student.exam = rand() % 10 + 1;
        student.final_mark_avg = calculateAvg(student.marks, student.exam);
        student.final_mark_med = calculateMedian(student.marks, student.exam);

        if (student.final_mark_avg < 5)
        {
            student.file = true;
        }
        else
        {
            student.file = false;
        }

        students.push_back(student);
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Studentu generavimas uztruko: " << elapsed_seconds.count() << "\n";

    return students;
}

std::ostream& operator<< (std::ostream& strm, const Student& s)
{
    std::stringstream ss;
    std::copy(s.marks.begin(), s.marks.end(), std::ostream_iterator<int>(ss, " "));
    std::string marks_text = ss.str();
    return strm << std::setw(15) << s.surname << std::setw(15) << s.name << " " << std::setw(15) << marks_text << s.final_mark_avg << std::setw(15) << s.final_mark_med << std::setw(15) << s.category << std::endl;

}

void writeStudents(int amount)
{
    auto start = std::chrono::steady_clock::now();

    std::vector<Student> students = generateStudents(amount);

    std::string file_name_1 = "studentai_kietekai" + std::to_string(students.size()) + ".txt";
    std::ofstream students_file_1(file_name_1);

    std::string file_name_2 = "studentai_vargsiukai" + std::to_string(students.size()) + ".txt";
    std::ofstream students_file_2(file_name_2);

    std::string file_name = "studentai" + std::to_string(students.size()) + ".txt";
    std::ofstream students_file(file_name);

    for (const Student& s : students)
    {
        students_file << s;
        /* if(s.file) {
            students_file_2 << s;
        }
        else
        {
            students_file_1 << s;
        } */
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Studentu irasymas i 2 failus uztruko: " << elapsed_seconds.count() << "\n";
}
