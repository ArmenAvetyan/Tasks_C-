#include "dirusers.hpp"
#include <utility>

Student::Student(std::string name)
    : User(std::move(name), 3, 14)
{
}

Student::~Student() = default;

double Student::getFineRate() const
{
    return 200.0;
}

size_t Student::getMaxDays() const
{
    return User::getMaxDays();
}

Lecturer::Lecturer(std::string name)
    : User(std::move(name), 10, 30)
{
}

Lecturer::~Lecturer() = default;

double Lecturer::getFineRate() const
{
    return 100.0;
}

size_t Lecturer::getMaxDays() const
{
    return User::getMaxDays();
}
