#include <iostream>
using namespace std;

void swapp(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int arr[] = {2, 1, 7, 3, 10, 4};

    int n = 6;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1 ; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapp(&arr[j], &arr[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}