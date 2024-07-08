//
// Created by x220 on 30.06.2024.
//

#include <iostream>
#include "BankAccount.h"

BankAccount::BankAccount() : balance(0.0) {}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::deposit(double amount) {
    transactions.push(amount);
}

void BankAccount::withdraw(double amount) {
    transactions.push(-amount);
}

void BankAccount::processTransactions() {
    while (!transactions.empty()) {
        double amount = transactions.front();
        transactions.pop();

        // Проверка доступности баланса перед списанием средств
        if (balance + amount < 0) {
            std::cout << "Недостаточно средств на счете для списания " << -amount << std::endl;
            continue;
        }

        balance += amount;
    }
    std::cout << "--Все транзакции обработаны --" << std::endl;
}

void BankAccount::printTransactionLog() const {
    std::cout << "Список транзакций:" << std::endl;
    std::queue<double> tempTransactions = transactions;
    double tempBalance = balance;
    while (!tempTransactions.empty()) {
        double amount = tempTransactions.front();
        tempTransactions.pop();

        // Проверка доступности баланса перед выводом транзакции
        if (tempBalance + amount < 0) {
            std::cout << "Недостаточно средств на счете для списания " << -amount << std::endl;
            continue;
        }

        tempBalance += amount;
        std::cout << "-> " << amount << std::endl;
    }
    std::cout << std::endl;
}