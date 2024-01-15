#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Employee {
public:
    int id;
    string name;

    Employee(int id, string name) : id(id), name(name) {
    }

    virtual void Print() {
        cout << "Id: " << id << " Name: " << name << endl;
    }

    virtual int CalculateSalary() {
        return 0;
    }
};

class SalaryEmployee : public Employee {
public:
    int monthly_salary;

    SalaryEmployee(int id, string name, int monthly_salary) : Employee(id, name), monthly_salary(monthly_salary) {
    }

    virtual void Print() {
        cout << "Id: " << id << " Name: " << name << " Salary: " << monthly_salary << endl;
    }

    virtual int CalculateSalary() const {
        return monthly_salary;
    }
};


class Employeelist {
public:
    vector<Employee *> employees;

    void Menu() {
        int value = 9;
        int quit = 0;

        while (value != quit) {
            cout << "Payroll Menu" << endl;
            cout << "============" << endl;
            cout << "(1) Add employees" << endl;
            cout << "(2) Write employees to file" << endl;
            cout << "(3) Read employees from file" << endl;
            cout << "(4) Print employees" << endl;
            cout << "(0) Quit" << endl;
            cout << "Please select: ";
            cin >> value;
            cout << endl;
            switch (value) {
                case 1:
                    cin.ignore();
                    Insert();
                    cout << endl;
                    break;
                case 2:
                    WriteToFile(employees);;
                    cout << endl;
                    break;
                case 3:
                    ReadFromFile();
                    cout << endl;
                    break;
                case 4:
                    Print(employees);
                    cout << endl;
                    break;
                case 0:
                    break;
                default:
                    cout << "Incorrect selection\n" << endl;
                    break;
            }
        }
    }

    void Insert() {
        string name = " ";
        string quit = "0";
        int id = 1, salary;

        while (name != quit) {
            cout << "Please enter employee name (0 to quit): ";
            getline(cin, name);
            if (name != quit) {
                cout << "Please enter salary: ";
                cin >> salary;
                employees.push_back(new SalaryEmployee(id, name, salary));
                id++;
                cin.ignore();
            }
        }
    }

    void WriteToFile(vector<Employee *> employees1) {
        string filename = "employee.csv";
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file " << filename << endl;
        }

        for (const auto employee: employees1) {
            vector<string> employeeData = {
                    to_string(employee->id),
                    employee->name,
                    to_string(employee->CalculateSalary())
            };
            file << myjoin(employeeData, ',') << endl;
        }
        file.close();
        cout << employees.size() << " employee(s) added to file " << filename << endl;
    }

    string myjoin(vector<string> lst, char sep) {
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
            vector<string> employeeData = mysplit(line, ',');
            if (employeeData.size() == 3) {
                int id, salary;
                string name;

                id = stoi(employeeData[0]);
                name = employeeData[1];
                salary = stoi(employeeData[2]);

                employees.push_back(new SalaryEmployee(id, name, salary));
            }
        }
        file.close();
        cout << employees.size() << " employee(s) read from file " << filename << endl;

    }

    vector<string> mysplit(string sentence, char sep) {
        vector<string> words_array;
        string temp;
        int i = 0;
        while (sentence[i] != '\0') {
            if (sentence[i] != sep) {
                temp += sentence[i];
            } else {
                words_array.push_back(temp);
                temp.clear();
            }
            i++;
        }
        words_array.push_back(temp);
        return words_array;
    }


    void Print(vector<Employee *> employees) {
        for (int i = 0; i < employees.size(); i++) {
            employees[i]->Print();
        }
    }
};

int main() {
    Employeelist myList = *new Employeelist();
    myList.Menu();
    return 0;
}



