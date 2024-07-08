#include "Employee.h"

#include <utility>

Employee::Employee(std::string  name, const std::string& surname, std::string  position)
        : name(std::move(name)), surname(surname), position(std::move(position)) {}

std::string Employee::getName() const {
    return name;
}

std::string Employee::getSurname() const {
    return surname;
}

std::string Employee::getPosition() const {
    return position;
}

void Employee::setName(const std::string& name) {
    this->name = name;
}

void Employee::setSurname(const std::string& surname) {
    this->surname = surname;
}

void Employee::setPosition(const std::string& position) {
    this->position = position;
}

bool Employee::operator==(const Employee& other) const {
    return name == other.name && surname == other.surname && position == other.position;
}