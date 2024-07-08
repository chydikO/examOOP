//
// Created by x220 on 30.06.2024.
//

#ifndef EXAMOOP_BANKACCOUNT_H
#define EXAMOOP_BANKACCOUNT_H

#include <queue>

class BankAccount {
private:
    double balance;
    std::queue<double> transactions;

public:
    BankAccount();

    [[nodiscard]] double getBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    void processTransactions();
    void printTransactionLog() const;
    };

#endif //EXAMOOP_BANKACCOUNT_H
