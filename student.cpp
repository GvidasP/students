#include "student.h"
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>

Student::Student(std::string n, std::string s, std::vector<int> m, int e, double avg, double med, std::string c)
{
	name = n;
	surname = s;
	marks = m;
	exam = e;
	final_mark_avg = avg;
	final_mark_med = med;
	category = c;
};

bool Student :: compareStudentsNames(const Student& a, const Student& b)
{
	return a.name < b.name;
}