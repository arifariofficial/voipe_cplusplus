/*
In this exercise we will extend Class Employee with HourlyEmployee and CommissionEmployee subclasses.

Define HourlyEmployee as a subclass of Employee class:

Write method AskSalary, which is used to query hour_rate and hours_worked attributes from the user.
Write method CalculateSalary, which is used to calculate salary using: hour_rate * hours_worked.
Define CommissionEmployee as a subclass of SalaryEmployee (which is a subclass of Employee).

Write method AskSalary, which is used to query attribute commission from the user.
Write method CalculateSalary, which is used to calculate salary using: monthly_salary + commission.
Payroll is printed using Class PayrollSystem.

Program menu as below:

Salary type
-----------
(1) Monthly
(2) Hourly
(3) Commission
(0) Quit
Please enter salary type:
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class for all types of employees
class Employee {
public:
    int id;
    string name;

    // Constructor with initialization list
    Employee(int id, string name) : id(id), name(name) {}

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Employee() = default;

    // Pure virtual function to be overridden by derived classes
    virtual void AskSalary() = 0;

    // Pure virtual function to be overridden by derived classes
    virtual int CalculateSalary() const = 0;
};

// Derived class for employees with monthly salary
class SalaryEmployee : public Employee {
public:
    int MonthlySalary;

    // Constructor with initialization list
    SalaryEmployee(int id, string name, int MonthlySalary) : Employee(id, name), MonthlySalary(MonthlySalary) {}

    // Implementation of AskSalary for SalaryEmployee
    void AskSalary() override {
        cout << "Please enter monthly salary: ";
        cin >> MonthlySalary;
    }

    // Implementation of CalculateSalary for SalaryEmployee
    int CalculateSalary() const override {
        return MonthlySalary;
    }
};

// Derived class for employees paid hourly
class HourlyEmployee : public Employee {
public:
    int hour_rate;
    int hours_worked;

    // Constructor with initialization list
    HourlyEmployee(int id, string name) : Employee(id, name) {}

    // Implementation of AskSalary for HourlyEmployee
    void AskSalary() override {
        cout << "Please enter hour rate: ";
        cin >> hour_rate;

        cout << "Please enter hours worked: ";
        cin >> hours_worked;
    }

    // Implementation of CalculateSalary for HourlyEmployee
    int CalculateSalary() const override {
        return hour_rate * hours_worked;
    }
};

// Derived class for employees with monthly salary and additional commission
class CommissionEmployee : public SalaryEmployee {
public:
    int commission;

    // Constructor with initialization list
    CommissionEmployee(int id, string name, int MonthlySalary) : SalaryEmployee(id, name, MonthlySalary) {}

    // Implementation of AskSalary for CommissionEmployee
    void AskSalary() override {
        SalaryEmployee::AskSalary();
        cout << "Please enter commission: ";
        cin >> commission;
    }

    // Implementation of CalculateSalary for CommissionEmployee
    int CalculateSalary() const override {
        return SalaryEmployee::CalculateSalary() + commission;
    }
};

// Class for handling payroll calculations
class PayrollSystem {
public:
    // Method to calculate and print payroll for employees
    static void CalculatePayroll(const vector<Employee *> &employees);
};

// Implementation of CalculatePayroll for PayrollSystem
void PayrollSystem::CalculatePayroll(const vector<Employee *> &employees) {
    for (const auto &employee : employees) {
        cout << "Employee Payroll" << endl;
        cout << "================" << endl;
        cout << "Payroll for: " << employee->id << " - " << employee->name << endl;
        cout << "- Check amount: " << employee->CalculateSalary() << endl;
        cout << "\n";
    }
}

// Main function
int main() {
    vector<Employee *> employees; // Using pointer to handle polymorphism
    int choice;

    while (true) {
        cout << "Salary type" << endl;
        cout << "-----------" << endl;
        cout << "(1) Monthly" << endl;
        cout << "(2) Hourly" << endl;
        cout << "(3) Commission" << endl;
        cout << "(0) Quit" << endl;
        cout << "Please enter salary type: ";
        cin >> choice;

        if (choice == 0) {
            cout << "\n";
            break;
        }

        string name;
        cout << endl << "Please enter employee name: ";
        cin.ignore(); // Clear the buffer;
        getline(cin, name);

        Employee *employee = nullptr;

        switch (choice) {
            case 1:
                employee = new SalaryEmployee(employees.size() + 1, name, 0);
                break;
            case 2:
                employee = new HourlyEmployee(employees.size() + 1, name);
                break;
            case 3:
                employee = new CommissionEmployee(employees.size() + 1, name, 0);
                break;
            default:
                cout << "Invalid choice." << endl;
                continue;
        }

        // Ask for specific salary details based on employee type
        employee->AskSalary();
        employees.push_back(employee);
    }

    // Calculate and print payroll using PayrollSystem
    PayrollSystem::CalculatePayroll(employees);

    // Clean up memory;
    for (auto employee : employees) {
        delete employee;
    }

    return 0;
}


/*
Example output:
Salary type
-----------
(1) Monthly
(2) Hourly
(3) Commission
(0) Quit
Please enter salary type: 1

Please enter employee name: Jane Doe
Please enter monthly salary: 5555
Salary type
-----------
(1) Monthly
(2) Hourly
(3) Commission
(0) Quit
Please enter salary type: 2

Please enter employee name: John Johnson
Please enter hour rate: 60
Please enter hours worked: 45
Salary type
-----------
(1) Monthly
(2) Hourly
(3) Commission
(0) Quit
Please enter salary type: 3

Please enter employee name: Richard Roe
Please enter monthly salary: 2500
Please enter commission: 777
Salary type
-----------
(1) Monthly
(2) Hourly
(3) Commission
(0) Quit
Please enter salary type: 0

Employee Payroll
================
Payroll for: 1 - Jane Doe
- Check amount: 5555

Employee Payroll
================
Payroll for: 2 - John Johnson
- Check amount: 2700

Employee Payroll
================
Payroll for: 3 - Richard Roe
- Check amount: 3277
 */