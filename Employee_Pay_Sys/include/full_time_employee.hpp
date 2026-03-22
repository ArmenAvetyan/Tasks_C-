#pragma once
#include "employee.hpp"
#include "bonus_eligible.hpp"

class FullTimeEmployee : public Employee, public BonusEligible
{
    public:
        FullTimeEmployee();
    public:
        double calculateSalary() const override;
        double calculateBonus() const override;
        void displayInfo() const override;
    public:
        static double inMonthSalary();
    private:
        double monthlySalary {};
};
