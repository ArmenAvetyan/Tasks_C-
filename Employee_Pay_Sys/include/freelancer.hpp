#pragma once
#include "employee.hpp"

class Freelancer : public Employee
{
    public:
        Freelancer();
    public:
        double calculateSalary() const override;
        void displayInfo() const override;
    public:
        static int inprojectsCompleted();
        static double inpaymentPerProject();
    private:
        int projectsCompleted {};
        double paymentPerProject {};
};
