#pragma once
#include <string>

class Employee
{
    public:
        Employee(int id, std::string name);
        virtual ~Employee();
    public:
        virtual double calculateSalary() const = 0;
    public:
        virtual void displayInfo() const;
        int getId() const noexcept;
        std::string getName() const noexcept;
    public:
        static int inId();
        static std::string inName();
    private:
        int m_id {};
        std::string m_name {};
};
