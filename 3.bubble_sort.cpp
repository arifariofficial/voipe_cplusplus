/*
Make function bubbleSort using bubble sort algorithm to sort numbers given by user;
order numbers into the ascending order. Function header and return clauses are given
to you. Function gets unsorted table and number of elements as function parameters.

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the
adjacent elements if they are in wrong order.
 */


#include <iostream>

using namespace std;

int *bubblesort(int a[], int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {    //Second loop to compare every 2 items in the array
            if (a[j] < a[j - 1]) {       //swapping items
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
    return a;
}

int bubble_sort() {
    int number;
    cout << "Please Enter the Total Number of Elements : ";
    cin >> number;
    int list[number];
    for (int i = 0; i < number; i++) {
        int value;
        cout << "Please enter the " << i + 1 << " Element: ";
        cin >> value;
        list[i] = value;
    }
    int *sorted = bubblesort(list, number);
    cout << "The Sorted List in Ascending Order: [";
    for (int i = 0; i < number - 1; i++) {
        cout << sorted[i] << ", ";
    }
    cout << sorted[number - 1] << "]" << endl;

    return 0;
}

/*
Example output:
Please Enter the Total Number of Elements : 5
Please enter the 1 Element: 4
Please enter the 2 Element: 3
Please enter the 3 Element: -1
Please enter the 4 Element: 9
Please enter the 5 Element: 6
The Sorted List in Ascending Order: [-1, 3, 4, 6, 9]
*/