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
    int arr[5] = {3, 5, 1, 9, 0};
    int min;
    int i;
    int j;
    for (i = 0; i < 5 - 1; i++)
    {
        min = i;
        for (j = i + 1; j < 5 ; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
                
            }
        }
        
        if(min != i )
        {
            swapp(&arr[min], &arr[i]);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}