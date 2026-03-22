#include "freelancer.hpp"
#include <iostream>
#include <print>

Freelancer::Freelancer() : Employee{inId(), inName()}, projectsCompleted{inprojectsCompleted()}, paymentPerProject{inpaymentPerProject()} {}

double Freelancer::calculateSalary() const
{
    return paymentPerProject * projectsCompleted;
}

void Freelancer::displayInfo() const
{
    Employee::displayInfo();

    std::println("Freelancer\nProjects Completed: {}\nPayment Per Project: {}\nSalary: {}", 
                projectsCompleted, paymentPerProject, calculateSalary());
}

int Freelancer::inprojectsCompleted()
{
    int procount {};
    std::print("Enter completed projects count: ");
    std::cin >> procount;
    return procount;
}

double Freelancer::inpaymentPerProject()
{
    double projectpay {};
    std::print("Enter payment for per project: ");
    std::cin >> projectpay;
    return projectpay;
}
