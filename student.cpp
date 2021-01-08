#include "student.h"
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>

bool Student :: compareStudentsNames(const Student& a, const Student& b)
{
	return a.name < b.name;
}
