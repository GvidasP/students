#include "helper.h"
#include "student.h"

#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <iterator>
#include <chrono>

int median(const std::vector<int>& numbers)
{
    int size = numbers.size();           // vectors know how many elements they have
    std::vector<int> copy = numbers;     // we copy the vector into a local, that we will modify later, leaving numbers unchanged
    std::sort(copy.begin(), copy.end()); // sort is a std:: function
    return (size % 2) ?                  // this is a single expression that chooses from two subexpressions. It is called (the) "ternary operator" (ternary being of three parameters)
        copy[size / 2]
        :                                     // even
        (copy[size / 2] + copy[(size / 2) - 1]) / 2; // odd
}

std::vector<Student> sortStudents(std::vector<Student> students)
{
    auto start = std::chrono::steady_clock::now();

    std::vector<Student> vargsiukai;

    // std::partition_copy(students.begin(), students.end(), vargsiukai.begin(), kietekai.begin(), [](Student s){return s.final_mark_avg < 5;});

    //std::partition_copy(begin(students), end(students), back_inserter(vargsiukai), back_inserter(kietekai), [](Student s){ return s.final_mark_avg < 5; });

    std::remove_copy_if(begin(students), end(students), back_inserter(vargsiukai), [](Student s) { return s.getFinalMarkAvg() < 5; });

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Studentu rusiavimas i 2 kategorijas uztruko: " << elapsed_seconds.count() << "\n";

    return vargsiukai;
}
std::vector<Student> readStudents(std::string fileName) {
	auto start = std::chrono::steady_clock::now(); // Start time

	try {
		std::ifstream ifs(fileName);

		if (!ifs.is_open()) {
			throw("Failas neegzistuoja");
		}

		std::vector<Student> students;
		std::string line;

		std::getline(ifs, line); // Skip first line

		while (std::getline(ifs, line)) {
			std::istringstream iss(line);
			std::istream_iterator<std::string> begin(iss), end;
			std::vector<std::string> tokens(begin, end);
			int temp = 2;

			Student student;
			std::vector<int> marks;

			student.setName(tokens[0]);
			student.setSurname(tokens[1]);

			for (int i = 0; i < 7; i++)
			{
				marks.push_back(stoi(tokens[temp]));
				temp++;
			}

			student.setMarks(marks);
			student.setExam(stoi(tokens[7]));

			temp = 2;

			students.push_back(student);
		}

		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		std::cout << "Studentu nuskaitymas is failo uztruko: " << elapsed_seconds.count() << "\n";

		return students;
	}
	catch (const char* e)
	{
		std::cout << "Exception: " << e << "\n";
	}
}

