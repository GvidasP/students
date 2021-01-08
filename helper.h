#pragma once

#include "student.h"
#include <vector>
#include <list>

int median(const std::vector<int>& numbers);

bool compareString(Student& a, Student& b);

std::vector<Student> readStudents(std::string fileName);

std::vector<std::vector<Student> > sortStudents(std::vector<Student> students, int option);

std::vector<std::string> split(const std::string &s, char delim);

