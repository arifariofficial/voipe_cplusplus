/*
In this exercise we will put together extended Employee class exercise and the file handling exercise to make complete PayrollSystem with file handling.

Remember that names and salaries are asked from user with option 1, but must be handled also from csv-file with option 3, so you have to indentify salarytype.
Duplicate employees are not allowed.
Program must save original values like hour_rate, not calculated salary.
Create action menu as below:


Payroll Menu
============
(1) Add employees
(2) Write employees to file
(3) Read employees from file
(4) Print payroll
(0) Quit
Please select:
Create Salary type menu as below:

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
#include <fstream>

using namespace std;

// Base class for all types of employees
class Employee {
public:
    int id;
    string name;
    string code;

    // Constructor
    Employee(int id, const string &name, const string &code) : id(id), name(name), code(code) {}

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Employee() = default;

    // Pure virtual function to be overridden by derived classes
    virtual void AskSalary() = 0;

    // Pure virtual function to be overridden by derived classes
    virtual int CalculateSalary() const = 0;

    // Virtual function to print employee details
    virtual void Print() const {
        cout << "Id: " << id << " Name: " << name << endl;
    }
};

// Derived class for employees with monthly salary
class SalaryEmployee : public Employee {
public:
    int monthlySalary;

    // Constructor
    SalaryEmployee(int id, const string &name, const string &code, int monthlySalary)
            : Employee(id, name, code), monthlySalary(monthlySalary) {}

    // Implementation of AskSalary for SalaryEmployee
    void AskSalary() override {
        cout << "Please enter monthly salary: ";
        cin >> monthlySalary;
    }

    // Implementation of CalculateSalary for SalaryEmployee
    int CalculateSalary() const override {
        return monthlySalary;
    }
};

// Derived class for employees paid hourly
class HourlyEmployee : public Employee {
public:
    int hourRate;
    int hoursWorked;

    // Constructor
    HourlyEmployee(int id, const string &name, const string &code, int hourRate, int hoursWorked)
            : Employee(id, name, code), hourRate(hourRate), hoursWorked(hoursWorked) {}

    // Implementation of AskSalary for HourlyEmployee
    void AskSalary() override {
        cout << "Please enter hour rate: ";
        cin >> hourRate;

        cout << "Please enter hours worked: ";
        cin >> hoursWorked;
    }

    // Implementation of CalculateSalary for HourlyEmployee
    int CalculateSalary() const override {
        return hourRate * hoursWorked;
    }
};

// Derived class for employees with monthly salary and additional commission
class CommissionEmployee : public SalaryEmployee {
public:
    int commission;

    // Constructor
    CommissionEmployee(int id, const string &name, int commission, int monthlySalary, const string &code)
            : SalaryEmployee(id, name, code, monthlySalary), commission(commission) {}

    // Implementation of AskSalary for CommissionEmployee
    void AskSalary() override {
        SalaryEmployee::AskSalary();
        cout << "Please enter commission: ";
        cin >> commission;
    }

    // Implementation of CalculateSalary for CommissionEmployee
    int CalculateSalary() const override {
        return monthlySalary + commission;
    }
};

// Class to manage a list of employees
class EmployeeList {
public:
    vector<Employee *> employees;

    // Destructor to ensure proper cleanup
    ~EmployeeList() {
        ClearEmployees();
    }

    // Clears the list and deletes allocated memory
    void ClearEmployees() {
        for (auto emp: employees) {
            delete emp;
        }
        employees.clear();
    }

    // Main menu to interact with the program
    void Menu() {
        int choice;

        while (true) {
            cout << "Payroll Menu" << endl;
            cout << "============" << endl;
            cout << "(1) Add Employees" << endl;
            cout << "(2) Write Employees to File" << endl;
            cout << "(3) Read Employees from File" << endl;
            cout << "(4) Print Payroll" << endl;
            cout << "(0) Quit" << endl;
            cout << "Please select: ";
            cin >> choice;
            cout << "\n";

            if (choice == 0) {
                break;
            }

            switch (choice) {
                case 1:
                    cin.ignore();
                    Insert();
                    cout << endl;
                    break;
                case 2:
                    WriteToFile(employees);
                    break;
                case 3:
                    ReadFromFile();
                    break;
                case 4:
                    CalculatePayroll(employees);
                    break;
                case 0:
                    break;
                default:
                    cout << "Incorrect selection\n" << endl;
                    break;
            }
        }
    }

    // Calculates and prints payroll for each employee
    void CalculatePayroll(const vector<Employee *> &employeesCalculate) {
        for (const auto emp: employeesCalculate) {
            cout << "Employee Payroll" << endl;
            cout << "================" << endl;
            cout << "Payroll for: " << emp->id << " - " << emp->name << endl;

            // Check the type of employee and calculate the salary accordingly
            if (auto salaryEmployee = dynamic_cast<SalaryEmployee *>(emp)) {
                cout << "- Check amount: " << salaryEmployee->CalculateSalary() << endl;
            } else if (auto hourlyEmployee = dynamic_cast<HourlyEmployee *>(emp)) {
                cout << "- Check amount: " << hourlyEmployee->CalculateSalary() << endl;
            } else if (auto commissionEmployee = dynamic_cast<CommissionEmployee *>(emp)) {
                cout << "- Check amount: " << commissionEmployee->CalculateSalary() << endl;
            } else {
                cout << "- Check amount: N/A (Unknown employee type)" << endl;
            }

            cout << "\n";
        }
    }

    // Inserts a new employee into the list
    void Insert() {
        int choice;

        while (true) {
            cout << "Salary Type" << endl;
            cout << "-----------" << endl;
            cout << "(1) Monthly" << endl;
            cout << "(2) Hourly" << endl;
            cout << "(3) Commission" << endl;
            cout << "(0) Quit" << endl;
            cout << "Please enter salary type: ";
            cin >> choice;

            if (choice == 0) {
                break;
            }

            string name;
            cout << endl << "Please enter employee name: ";
            cin.ignore(); // Clear the buffer;
            getline(cin, name);

            Employee *employee;

            switch (choice) {
                case 1:
                    employee = new SalaryEmployee(employees.size() + 1, name, "S", 0);
                    break;
                case 2:
                    employee = new HourlyEmployee(employees.size() + 1, name, "H", 0, 0);
                    break;
                case 3:
                    employee = new CommissionEmployee(employees.size() + 1, name, 0, 0, "C");
                    break;
                default:
                    cout << "Invalid choice." << endl;
                    continue;
            }

            // Ask for specific salary details based on employee type
            employee->AskSalary();
            employees.push_back(employee);
        }
    }

    // Writes employee data to a file
    void WriteToFile(const vector<Employee *> &employeesWrite) {
        string filename = "employee.csv";
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file " << filename << endl;
            return;
        }

        for (const auto employee: employeesWrite) {
            vector<string> employeeData;
            employeeData.push_back(to_string(employee->id));
            employeeData.push_back(employee->name);
            employeeData.push_back(employee->code);

            // Handle specific attributes for different employee types
            if (auto hourlyEmployee = dynamic_cast<HourlyEmployee *>(employee)) {
                employeeData.push_back(to_string(hourlyEmployee->hourRate));
                employeeData.push_back(to_string(hourlyEmployee->hoursWorked));
            } else if (auto commissionEmployee = dynamic_cast<CommissionEmployee *>(employee)) {
                employeeData.push_back(to_string(commissionEmployee->monthlySalary));
                employeeData.push_back(to_string(commissionEmployee->commission));
            } else {
                employeeData.push_back(to_string(employee->CalculateSalary()));
            }

            file << MyJoin(employeeData, ',') << endl;
        }
        file.close();
        cout << employees.size() << " employee(s) added to file " << filename << endl;
    }

    // Reads employee data from a file
    void ReadFromFile() {
        employees.clear();
        string filename = "employee.csv";
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file " << filename << endl;
            return;
        }

        string line;

        while (getline(file, line)) {
            vector<string> employeeData = MySplit(line, ',');

            if (employeeData.size() >= 4) {
                int id = stoi(employeeData[0]);
                string name = employeeData[1];
                string code = employeeData[2];

                // Create the appropriate type of employee based on the code
                if (code == "S") {
                    int salary = stoi(employeeData[3]);
                    employees.push_back(new SalaryEmployee(id, name, code, salary));
                } else if (code == "H") {
                    int hourRate = stoi(employeeData[3]);
                    int hoursWorked = stoi(employeeData[4]);
                    employees.push_back(new HourlyEmployee(id, name, code, hourRate, hoursWorked));
                } else if (code == "C") {
                    int commission = stoi(employeeData[3]);
                    int monthlySalary = stoi(employeeData[4]);
                    employees.push_back(new CommissionEmployee(id, name, commission, monthlySalary, code));
                }
            }
        }
        file.close();
        cout << employees.size() << " employee(s) read from file " << filename << endl;
    }

    // Joins a vector of strings into a single string using a separator
    string MyJoin(const vector<string> &lst, char sep) const {
        string str;
        int i = 0;
        while (i < lst.size()) {
            str.append(lst[i]);
            if (i != lst.size() - 1)
                str.push_back(sep);
            i++;
        }
        return str;
    }

    // Splits a string into a vector of strings using a separator
    vector<string> MySplit(const string &sentence, char sep) const {
        vector<string> wordsArray;
        string temp;
        int i = 0;
        while (sentence[i] != '\0') {
            if (sentence[i] != sep) {
                temp += sentence[i];
            } else {
                wordsArray.push_back(temp);
                temp.clear();
            }
            i++;
        }
        wordsArray.push_back(temp);
        return wordsArray;
    }

    // Prints details of employees in the provided vector
    void Print(const vector<Employee *> &employeesPrint) const {
        for (int i = 0; i < employeesPrint.size(); i++) {
            employeesPrint[i]->Print();
        }
    }
};

int main() {
    EmployeeList myList;
    myList.Menu();

    myList.ClearEmployees(); // Ensure memory cleanup before exiting

    return 0;
}

/*
Example output:
Payroll menu
============
(1) Add employees
(2) Write employees to file
(3) Read employees from file
(4) Print payroll
(0) Quit
Please select: 1

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

Payroll menu
============
(1) Add employees
(2) Write employees to file
(3) Read employees from file
(4) Print payroll
(0) Quit
Please select: 4

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

Payroll menu
============
(1) Add employees
(2) Write employees to file
(3) Read employees from file
(4) Print payroll
(0) Quit
Please select: 2

3 employee(s) added to file employee.csv
Payroll menu
============
(1) Add employees
(2) Write employees to file
(3) Read employees from file
(4) Print payroll
(0) Quit
Please select: 3

3 employee(s) read from file employee.csv
Payroll menu
============
(1) Add employees
(2) Write employees to file
(3) Read employees from file
(4) Print payroll
(0) Quit
Please select: 1

Salary type
-----------
(1) Monthly
(2) Hourly
(3) Commission
(0) Quit
Please enter salary type: 2

Please enter employee name: Mark Moe
Please enter hour rate: 30
Please enter hours worked: 15
Salary type
-----------
(1) Monthly
(2) Hourly
(3) Commission
(0) Quit
Please enter salary type: 0

Payroll menu
============
(1) Add employees
(2) Write employees to file
(3) Read employees from file
(4) Print payroll
(0) Quit
Please select: 4

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

Employee Payroll
================
Payroll for: 4 - Mark Moe
- Check amount: 450

Payroll menu
============
(1) Add employees
(2) Write employees to file
(3) Read employees from file
(4) Print payroll
(0) Quit
Please select: 0
*/