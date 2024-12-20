#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// ������� ����� ��� ����������� �����
class BankAccount {
protected:
    int accountNumber;  // ����� �����
    string ownerName;   // ��� ���������
    double balance;     // ������

public:
    // �����������
    BankAccount(int accNum, string name, double initialBalance)
        : accountNumber(accNum), ownerName(name), balance(initialBalance) {}

    // ����� ��� ���������� �����
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "���������� �� �����: " << amount << " ���." << endl;
        }
        else {
            cout << "����� ���������� ������ ���� �������������." << endl;
        }
    }

    // ����� ��� ������ �������
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "������ �����: " << amount << " ���." << endl;
        }
        else {
            cout << "������������ ������� ��� ������." << endl;
        }
    }
    // ����� ��� ������ ���������� � �����
    void display() const {
        cout << "����� �����: " << accountNumber << endl;
        cout << "��������: " << ownerName << endl;
        cout << "������: " << fixed << setprecision(2) << balance << " ���." << endl;
    }
};

// ����������� ����� ��� ��������������� �����
class SavingsAccount : public BankAccount {
private:
    double interestRate; // ���������� ������

public:
    // �����������
    SavingsAccount(int accNum, string name, double initialBalance, double rate)
        : BankAccount(accNum, name, initialBalance), interestRate(rate) {}

    // ����� ��� ���������� ���������
    void addInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "��������� ��������: " << fixed << setprecision(2) << interest << " ���." << endl;
    }

    // ��������������� ������ ������ ���������� � �����
    void display() const {
        BankAccount::display();
        cout << "���������� ������: " << fixed << setprecision(2) << interestRate << "%" << endl;
    }
};

int main() {
    // ������� ������ �������� ����������� �����
    BankAccount account1(123456, "Alice", 1000.00);
    account1.display();

    // ���������� � ������ �������
    account1.deposit(500.00);
    account1.withdraw(200.00);
    account1.display();

    // ������� ������ ��������������� �����
    SavingsAccount savings1(987654, "Bob", 5000.00, 5.0);
    savings1.display();

    // ����������, ������ � ���������� ���������
    savings1.deposit(1000.00);
    savings1.withdraw(1500.00);
    savings1.addInterest();  // ���������� ���������
    savings1.display();

    return 0;
}