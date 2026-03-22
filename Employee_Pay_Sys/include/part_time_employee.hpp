#pragma once
#include "employee.hpp"

class PartTimeEmployee : public Employee
{
    public:
        PartTimeEmployee();
    public:
        double calculateSalary() const override;
        void displayInfo() const override;
    public:
        static double inhourlyRate();
        static int inhoursWorked();
    private:
        double hourlyRate {};
        int hoursWorked {};
};
