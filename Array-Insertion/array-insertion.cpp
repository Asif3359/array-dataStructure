#include <iostream>
using namespace std;

int main()
{
    // array insertion operation
    int array[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Before Insertion"
         << "\n";
    int size = 10;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ",";
    }
    cout << "\n";
    int position;
    cout << "Enter position to insert "
         << ": ";
    cin >> position;
    cout << "Enter Number  to insert "
         << ": ";
    int number;
    cin >> number;

    // operation to insert a number by position
    for (int i = size - 1; i >= position - 1; i--)
    {
        array[i+1] = array[i];
    }
    array[position - 1] = number;
    size++;


    cout << "After  insert "
         << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ",";
    }
}