#pragma once

#include "student.h"

#include <string>
#include <vector>

std::string writeStudents(int amount, std::string students_filename);

void writeInputStudents(std::vector<Student> students, std::string students_filename="studentai");

double calculateAvg(std::vector<int> marks, int exam);

double calculateMedian(std::vector<int> marks, int exam);
