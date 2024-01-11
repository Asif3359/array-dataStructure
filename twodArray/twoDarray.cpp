#include <iostream>
using namespace std;

int main()
{
    // array insertion operation
    int array[10][10];

    int row, col;
    cout << "Enter Row and Column" << endl;
    cin >> row >> col;

    cout << "Enter Matrix Number" << " ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> array[i][j];
        }
    }

    cout << "After initialize array" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << array[i][j] << " ";
        }
    }

    return 0;
}