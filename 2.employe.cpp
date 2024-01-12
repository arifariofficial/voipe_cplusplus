/*
Make class Employee and its initialization method. Employee-class
will have 2 attributes: id and name.

Make program, which:
fills the vector (vector<Employee>) with objects of Employee class. Id is a serial
number from 1 and name will be asked from user and is given in a form "Firstname Surname".
Use getline (cin,name) to read name.
ends when user gives '0' instead of a name.
in the end prints all Employees from the vector in a format shown in example below.
Example output:
Please enter employee name (0 to quit): Jane Doe
Please enter employee name (0 to quit): John Johnson
Please enter employee name (0 to quit): Richard Roe
Please enter employee name (0 to quit): 0
Id: 1 Name: Jane Doe
Id: 2 Name: John Johnson
Id: 3 Name: Richard Roe
*/

#include <iostream>
#include <vector>

using namespace std;

class Employee {
public:
    int id = 0;
    string name;

    void SetName(string new_name);

    void SetId(int new_id);

    Employee(int new_id, string new_name);
};

void Employee::SetName(string new_name) {
    name = new_name;
}

void Employee::SetId(int new_id) {
    id = new_id;
}

Employee::Employee(int new_id, string new_name) {
    id = new_id;
    name = new_name;
}

int employee() {
    vector<Employee> employee;
    string name;
    int id = 1;

    while (name != "0") {
        cout << "Please enter employee name (0 to quit): ";
        getline(cin, name);
        if (name != "0") {
            employee.push_back(Employee(id, name));
        }
        id++;
    }

    for (const auto &x: employee) {
        cout << "Id: " << x.id << " Name: " << x.name << endl;
    }

    return 0;
}

/*
Example output:
Please enter employee name (0 to quit): Jane Doe
Please enter employee name (0 to quit): John Johnson
Please enter employee name (0 to quit): Richard Roe
Please enter employee name (0 to quit): 0
Id: 1 Name: Jane Doe
Id: 2 Name: John Johnson
Id: 3 Name: Richard Roe
*/