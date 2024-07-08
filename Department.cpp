#include "Department.h"
#include <iostream>
#include <utility>

Department::Department(std::string  name) : name(std::move(name)) {}

void Department::addEmployee(const std::string& position, const Employee& employee) {
    for (const auto& entry : employeesByPosition) {
        for (const auto& existingEmployee : entry.second) {
            if (existingEmployee == employee) {
                std::cout << "Сотрудник уже присутствует в департаменте." << std::endl;
                return;
            }
        }
    }

    employeesByPosition[position].push_back(employee);
}

std::vector<Employee> Department::findEmployeesByPosition(const std::string& position) const {
    if (employeesByPosition.count(position) > 0) {
        return employeesByPosition.at(position);
    }
    return {};
}

void Department::printReport() const {
    std::cout << "Департамент: " << name << "." << std::endl;
    for (const auto& entry : employeesByPosition) {
        std::cout << "Должность: " << entry.first << ", Кол-во сотрудников: " << entry.second.size() << std::endl;
        std::cout << "Сротрудники: " << std::endl;
        for (const auto& employee : entry.second) {
            std::cout << "- " << employee.getName() << " " << employee.getSurname() << std::endl;
        }
        std::cout << std::endl;
    }
}

std::vector<Employee> Department::findEmployeesBySurname(const std::string& surname) const {
    std::vector<Employee> result;
    for (const auto& entry : employeesByPosition) {
        for (const auto& employee : entry.second) {
            if (employee.getSurname() == surname) {
                result.push_back(employee);
            }
        }
    }
    return result;
}

const std::string &Department::getName() const {
    return name;
}
