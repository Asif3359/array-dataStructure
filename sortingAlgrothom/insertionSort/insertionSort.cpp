#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 3, 9, 4, 8, 2};
    int n = 6;
    int key;

    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0; 
}