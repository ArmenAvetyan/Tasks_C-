#include "part_time_employee.hpp"
#include <iostream>
#include <print>

PartTimeEmployee::PartTimeEmployee() : Employee{inId(), inName()}, hourlyRate{inhourlyRate()}, hoursWorked{inhoursWorked()} {}

double PartTimeEmployee::calculateSalary() const
{
    return hourlyRate * hoursWorked;
}

void PartTimeEmployee::displayInfo() const
{
    Employee::displayInfo();

    std::println("Part Time Employee\nHourly Rate: {}\nHours Worked: {}\nSalary: {}", 
                            hourlyRate, hoursWorked, calculateSalary());
}

double PartTimeEmployee::inhourlyRate()
{
    double rate {};
    std::print("Enter hourly rate: ");
    std::cin >> rate;
    return rate;
}

int PartTimeEmployee::inhoursWorked()
{
    int hour {};
    std::print("Enter hours worked: ");
    std::cin >> hour;
    return hour;
}
