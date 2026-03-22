#include "employee.hpp"
#include <iostream>
#include <string>
#include <print>

Employee::Employee(int id, std::string name) : m_id{id}, m_name{name} {}

Employee::~Employee() {}

void Employee::displayInfo() const
{
    std::println("ID: {}\nName: {}", getId(), getName());
}

int Employee::getId() const noexcept
{
    return m_id;
}

std::string Employee::getName() const noexcept
{
    return m_name;
}

int Employee::inId()
{
    int id {};
    std::print("Enter ID: ");
    std::cin >> id;
    return id;
}

std::string Employee::inName()
{
    std::string name{};
    std::print("Enter name: ");
    std::getline(std::cin >> std::ws, name);
    return name;
}
