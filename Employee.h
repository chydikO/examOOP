//
// Created by x220 on 30.06.2024.
//

#ifndef EXAMOOP_EMPLOYEE_H
#define EXAMOOP_EMPLOYEE_H

#include <string>

class Employee {
private:
    std::string name;
    std::string surname;
    std::string position;

public:
    Employee(std::string  name, const std::string& surname, std::string  position);

    std::string getName() const;
    std::string getSurname() const;
    std::string getPosition() const;

    void setName(const std::string& name);
    void setSurname(const std::string& surname);
    void setPosition(const std::string& position);
    bool operator==(const Employee& other) const;
};


#endif //EXAMOOP_EMPLOYEE_H
