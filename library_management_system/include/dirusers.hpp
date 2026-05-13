#pragma once
#include "user.hpp"
#include <string>
#include <cstddef>

class Student : public User
{
    public:
        Student(std::string name);
        ~Student();
        double getFineRate() const override;
        size_t getMaxDays() const override;
};

class Lecturer : public User
{
    public:
        Lecturer(std::string name);
        ~Lecturer();
        double getFineRate() const override;
        size_t getMaxDays() const override;
};
