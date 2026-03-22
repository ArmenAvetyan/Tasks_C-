#include "pay_sys.hpp"
#include "employee.hpp"
#include <print>

PayrollSystem::PayrollSystem() = default;

PayrollSystem::~PayrollSystem() noexcept
{
    for (Employee* emp : employees)
    {
        delete emp;
    }
}

void PayrollSystem::findEmployee(int id) const 
{
    for (Employee* emp : employees)
    {
        if(emp->getId() == id) 
        {
            std::println(); 
            emp->displayInfo();
            return;
        }
    }
    std::println("ID is not correct!");
}

void PayrollSystem::displayEmployees() const
{
    for (Employee* emp : employees)
    {
        std::println();
        emp->displayInfo();
    }
}

void PayrollSystem::calculateAllSalaries() const
{
    long int salary {};
    for (Employee* emp : employees)
    {
        salary += emp->calculateSalary();
    }
    std::println("\nAll salaries: {}", salary);
}

void PayrollSystem::addEmployee(Employee* emp)
{
    if (emp != nullptr)
    {
    employees.push_back(emp);
    } else
        std::println("pointer is null!");
}
