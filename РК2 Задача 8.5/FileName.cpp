#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Базовый класс для банковского счета
class BankAccount {
protected:
    int accountNumber;  // Номер счета
    string ownerName;   // Имя владельца
    double balance;     // Баланс

public:
    // Конструктор
    BankAccount(int accNum, string name, double initialBalance)
        : accountNumber(accNum), ownerName(name), balance(initialBalance) {}

    // Метод для пополнения счета
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Пополнение на сумму: " << amount << " руб." << endl;
        }
        else {
            cout << "Сумма пополнения должна быть положительной." << endl;
        }
    }

    // Метод для снятия средств
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снятие суммы: " << amount << " руб." << endl;
        }
        else {
            cout << "Недостаточно средств для снятия." << endl;
        }
    }
    // Метод для вывода информации о счете
    void display() const {
        cout << "Номер счета: " << accountNumber << endl;
        cout << "Владелец: " << ownerName << endl;
        cout << "Баланс: " << fixed << setprecision(2) << balance << " руб." << endl;
    }
};

// Производный класс для сберегательного счета
class SavingsAccount : public BankAccount {
private:
    double interestRate; // Процентная ставка

public:
    // Конструктор
    SavingsAccount(int accNum, string name, double initialBalance, double rate)
        : BankAccount(accNum, name, initialBalance), interestRate(rate) {}

    // Метод для начисления процентов
    void addInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Начислены проценты: " << fixed << setprecision(2) << interest << " руб." << endl;
    }

    // Переопределение метода вывода информации о счете
    void display() const {
        BankAccount::display();
        cout << "Процентная ставка: " << fixed << setprecision(2) << interestRate << "%" << endl;
    }
};

int main() {
    // Создаем объект обычного банковского счета
    BankAccount account1(123456, "Alice", 1000.00);
    account1.display();

    // Пополнение и снятие средств
    account1.deposit(500.00);
    account1.withdraw(200.00);
    account1.display();

    // Создаем объект сберегательного счета
    SavingsAccount savings1(987654, "Bob", 5000.00, 5.0);
    savings1.display();

    // Пополнение, снятие и начисление процентов
    savings1.deposit(1000.00);
    savings1.withdraw(1500.00);
    savings1.addInterest();  // Начисление процентов
    savings1.display();

    return 0;
}