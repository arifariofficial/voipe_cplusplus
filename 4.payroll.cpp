/*
Define first classes

PayrollSystem, having method CalculatePayroll and getting a list of employees as a parameter.
Method should calculate and print payroll for employees.
SalaryEmployee, a subclass of Employee. SalaryEmployee has its own attribute MonthlySalary and
method CalculateSalary, which will return the monthly salary of an employee.
Finally make then program, asking employee name as in previous Employee-exercise and also asking
monthly salary for SalaryEmployee-class object.
creating SalaryEmployee-objects and store them into a vector.
ending when user gives '0' instead of a name.
using at the end PayrollSystem to print Payroll for Employees in a format shown in the example below.
*/


#include <iostream>
#include <vector>
using namespace std;

class Employee {
public:
    int id;
    string name;

    Employee(int new_id, string new_name);
};

Employee::Employee(int new_id, string new_name) {
    id = new_id;
    name = new_name;
}

class SalaryEmployee : public Employee {
public:
    int MonthlySalary;

    int CalculateSalary() const;

    SalaryEmployee(int new_id, string new_name, int new_MonthlySalary);
};

SalaryEmployee::SalaryEmployee(int new_id, string new_name, int new_MonthlySalary) : Employee(new_id, new_name) {
    id = new_id;
    name = new_name;
    MonthlySalary = new_MonthlySalary;
}

int SalaryEmployee::CalculateSalary() const {
    return MonthlySalary;
}

void CalculatePayroll(const vector<SalaryEmployee> &employee);

int payroll() {

    vector<SalaryEmployee> employee;
    string name;
    int salary;
    int id = 1;

    while (name != "0") {
        cout << "Please enter employee name (0 to quit): ";
        getline(cin, name);
        if (name != "0") {
            cout << "Please enter salary: ";
            cin >> salary;
            employee.push_back(SalaryEmployee(id, name, salary));
        } else
            break;
        id++;
        cin.ignore();
    }
    CalculatePayroll(employee);
    return 0;
}

void CalculatePayroll(const vector<SalaryEmployee> &employee) {
    for (const auto &x: employee) {
        cout << "Employee Payroll" << endl;
        cout << "================" << endl;
        cout << "Payroll for: " << x.id << " - " << x.name << endl;
        cout << "- Check amount: " << x.CalculateSalary() << endl;
        cout <<"\n";
    }
}


/*
Please enter employee name (0 to quit): Jane Doe
Please enter salary: 5500
Please enter employee name (0 to quit): John Johnson
Please enter salary: 4500
Please enter employee name (0 to quit): Richard Roe
Please enter salary: 5050
Please enter employee name (0 to quit): 0
Employee Payroll
================
Payroll for: 1 - Jane Doe
- Check amount: 5500

Employee Payroll
================
Payroll for: 2 - John Johnson
- Check amount: 4500

Employee Payroll
================
Payroll for: 3 - Richard Roe
- Check amount: 5050
*/