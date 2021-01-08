#include "student.h"
#include "helper.h"
#include "generator.h"

#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <sstream>

using std::cin;
using std::cout;

int main()
{
    int m, option;
    std::string filename, generated_file_name;
    std::vector<Student> students;
    std::vector<std::vector<Student>> sorted_students;

    cout << "Automatinis studentu generavimas:\n\t0 - Generuoti\n\t1 - Negeneruoti\n";
    cin >> option;

    if (option == 0)
    {
        cout << "Generuojamu studentu skaicius: ";
        cin >> m;

        cout << "Failo pavadinimas: ";
        cin >> filename;

        cout << "Rusiavimo strategijos:\n\t0 - partition_copy\n\t1 - remove_copy_if\n";
        cin >> option;

        generated_file_name = writeStudents(m, filename);

        students = readStudents(generated_file_name);

        sorted_students = sortStudents(students, option);
    }

    cout << "Ivesti papildomus studentus:\n\t0 - Neivesti\n\t1 - Ivesti\n";
    cin >> option;

    switch (option)
    {
    case 0:
    {
        cout << "Darbas baigtas.";
    };

    case 1:
    {
        cout << "Failo pavadinimas: ";
        cin >> filename;

        cout << "Noredami iseiti, parasykite 'exit'\nVardas Pavarde | Egzamino pazymys | Pazymiai:\n";

        std::vector<std::vector<std::string>> students_string;
        std::string line;

        while (std::getline(std::cin, line))
        {
            std::string input;
            std::vector<std::string> student_info;
            Student student;

            if (line == "exit")
            {
                break;
            }
            std::istringstream stream(line);

            while (stream >> input)
            {
                student_info.push_back(input);
            }

            students_string.push_back(student_info);
        }

        for (std::vector<std::string> t : students_string)
        {
            if (t.size() <= 0)
                continue;

            Student student;
            std::vector<int> marks;

            std::transform(t.begin() + 2, t.end(), std::back_inserter(marks),
                           [](const std::string &str) { return std::stoi(str); });

            student.setName(t[0]);
            student.setSurname(t[1]);
            student.setExam(stoi(t[2]));
            student.setMarks(marks);
            student.setFinalMarkAvg(calculateAvg(marks, stoi(t[2])));
            student.setFinalMarkMed(calculateMedian(marks, stoi(t[2])));

            students.push_back(student);
        };

        writeInputStudents(students, filename);
    };
    };
    return 0;
}
