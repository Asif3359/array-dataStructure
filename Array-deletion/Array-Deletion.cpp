#include <iostream>
using namespace std;

int main()
{
    // arry deletion operation
    int array[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Before Deletion"
         << "\n";
    int size = 10;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ",";
    }
    cout << "\n";
    int position;
    cout << "Enter position to delete "
         << ": ";
    cin >> position;
    int number;

    // operation to delete a number by position
    number = array[position - 1];
    for (int i = position - 1; i <= size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    // array[position - 1] = number;3

    size--;

    cout << "After  delete "
         << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ",";
    }
    cout << "\n";
    cout << "After delete the deleted Number is  " << number
         << "\n";

    return 0;
}
