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