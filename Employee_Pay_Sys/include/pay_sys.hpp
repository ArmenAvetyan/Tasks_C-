#pragma once
#include "employee.hpp"
#include <vector>

class PayrollSystem
{
    public:
        PayrollSystem();
        ~PayrollSystem() noexcept;
    public:
        void findEmployee(int id) const;
        void displayEmployees() const;
        void calculateAllSalaries() const;
        void addEmployee(Employee* emp);
    private:
        std::vector<Employee*> employees {};
};
