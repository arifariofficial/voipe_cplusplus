/*
Make simple Supermarket -program,

having 10 products with prices in an array of integers as follows:
int prodprices[] = { 10, 14, 22, 33, 44, 13, 22, 55, 66, 77 };
asking (cin >> prodnbr) product number from 1 to 10 and summing its price to totalsum
and printing product number and price for every product as in example.
asking products until user gives '0' to quit the program (do while-loop).
printing  "Total:" and the total sum of prices.
asking "Payment:" from user and printing "Change:" and finally
calculating and printing the amount of change (payment - totalsum) to customer.

You must use in this program: [], while, cin, cout, endl

*/

#include <iostream>

using namespace std;

int super_market() {
    int prodprices[] = {10, 14, 22, 33, 44, 13, 22, 55, 66, 77};
    int num = 1, totalsum = 0, payment = 0;

    cout << "Supermarket" << endl;
    cout << "===========" << endl;

    while (num != 0) {
        cout << "Please select product (1-10) 0 to Quit: ";
        cin >> num;
        if (num > 0 && num < 11) {
            totalsum = totalsum + prodprices[num - 1];
            cout << "Product: " << num << " Price: " << prodprices[num - 1] << endl;

        } else if (num < 0 || num > 10) {
            cout << "Please select correct product (1-10)" << endl;
        }
    }

    cout << "Total: " << totalsum << endl;
    cout << "Payment: ";
    cin >> payment;
    cout << "Change: " << payment - totalsum << endl;

    return 0;
}

/*
Example output:
Supermarket
===========
Please select product (1-10) 0 to Quit: 1
Product: 1 Price: 10
Please select product (1-10) 0 to Quit: 6
Product: 6 Price: 13
Please select product (1-10) 0 to Quit: 11
Please select correct product (1-10)
Please select product (1-10) 0 to Quit: 10
Product: 10 Price: 77
Please select product (1-10) 0 to Quit: 5
Product: 5 Price: 44
Please select product (1-10) 0 to Quit: 0
Total: 144
Payment: 200
Change: 56
*/