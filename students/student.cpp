#include "student.h"


bool Student :: compareStudentsNames(const Student& a, const Student& b)
{
	return a.name < b.name;
}