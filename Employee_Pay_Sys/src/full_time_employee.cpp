#include "full_time_employee.hpp"
#include <iostream>
#include <print>

FullTimeEmployee::FullTimeEmployee() : Employee {inId(), inName()}, monthlySalary{inMonthSalary()} {}

double FullTimeEmployee::calculateSalary() const
{
    return monthlySalary + calculateBonus();
}

double FullTimeEmployee::calculateBonus() const
{
    return monthlySalary / 10;
}

void FullTimeEmployee::displayInfo() const
{
    Employee::displayInfo();

    std::println("Full Time Employee\nMonthly Salary: {}\nBonus: {}\nSalary: {}", 
                            monthlySalary, calculateBonus(), calculateSalary());
}

double FullTimeEmployee::inMonthSalary()
{
    double salary {};
    std::print("Enter Salary: ");
    std::cin >> salary;
    return salary;
}
