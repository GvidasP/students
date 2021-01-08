#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

#include <string>

class Human
{
protected:
    std::string name, surname;
public:
    Human() {};
    Human(std::string n, std::string s) : name{n}, surname{s} {};
    ~Human() {};

    const std::string &getName()
    {
        return name;
    };

    const std::string &getSurname()
    {
        return surname;
    }

    void setName(const std::string &n)
    {
        name = n;
    };

    void setSurname(const std::string &s)
    {
        surname = s;
    };
};

#endif // HUMAN_H_INCLUDED
