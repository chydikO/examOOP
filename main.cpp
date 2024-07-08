#include "department.h"
#include "BankAccount.h"
#include "Employee.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "---Task 1---" << std::endl;
    // Создание отдела
    Department department("Отдел разработки");

    // Создание сотрудников
    Employee employee1("Иван", "Иванов", "Разработчик");
    Employee employee2("Петр", "Петров", "Тестировщик");
    Employee employee3("Анна", "Сидорова", "Разработчик");

    // Добавление сотрудников в отдел
    department.addEmployee("Разработчик", employee1);
    department.addEmployee("Тестировщик", employee2);
    department.addEmployee("Разработчик", employee3);

    // Добавление сотрудника, который уже существует
    Employee duplicateEmployee("Иван", "Иванов", "Разработчик");
    department.addEmployee("Разработчик", duplicateEmployee);

    // Поиск сотрудников по позиции
    std::vector<Employee> employeesByPosition = department.findEmployeesByPosition("Разработчик");
    std::cout << "Сотрудники с позицией Разработчик:" << std::endl;
    for (const auto& employee : employeesByPosition) {
        std::cout << "Имя: " << employee.getName() << ", Фамилия: " << employee.getSurname() << ", Позиция: " << employee.getPosition() << std::endl;
    }

    // Поиск сотрудников по фамилии
    std::vector<Employee> employeesBySurname = department.findEmployeesBySurname("Иванов");
    std::cout << "Сотрудники с фамилией Иванов:" << std::endl;
    for (const auto& employee : employeesBySurname) {
        std::cout << "Имя: " << employee.getName() << ", Фамилия: " << employee.getSurname() << ", Позиция: " << employee.getPosition() << std::endl;
    }

    // Вывод отчета
    department.printReport();

    std::cout << "---Task 2---" << std::endl;
    BankAccount account;
    std::cout << "Начальный баланс: " << account.getBalance() << std::endl;

    account.deposit(100.0);
    account.withdraw(200.0); // Недостаточно средств на счете для списания 200.0
    account.deposit(50.0);
    account.withdraw(75.0);
    account.deposit(150.0);
    account.printTransactionLog();
    account.processTransactions();

    std::cout << "Конечный баланс:: " << account.getBalance() << std::endl;

    return 0;
}