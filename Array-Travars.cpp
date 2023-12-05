#include <iostream>

using namespace std;

int main()
{
    // sum with 10 an every element in  array ;

    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Befor Sum with 10 "
         << "\n";

    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << ",";
    }
    cout << '\n';
    cout << "Sum with 10 "
         << "\n";
    for (int i = 0; i < 10; i++)
    {
        array[i] = array[i] + 10;
    }

    cout << "After Sum with 10 "
         << "\n";
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << ", ";
    }
    cout << '\n';
    return 0;
}
