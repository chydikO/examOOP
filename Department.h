//
// Created by x220 on 30.06.2024.
//

#ifndef EXAMOOP_DEPARTMENT_H
#define EXAMOOP_DEPARTMENT_H

#include <string>
#include <vector>
#include <map>
#include "Employee.h"

class Department {
private:
    std::string name;
    std::map<std::string, std::vector<Employee>> employeesByPosition;

public:
    explicit Department(std::string  name);

    [[nodiscard]] const std::string &getName() const;

    void addEmployee(const std::string& position, const Employee& employee);
    [[nodiscard]] std::vector<Employee> findEmployeesByPosition(const std::string& position) const;
    void printReport() const;
    [[nodiscard]] std::vector<Employee> findEmployeesBySurname(const std::string& surname) const;
};

#endif //EXAMOOP_DEPARTMENT_H
