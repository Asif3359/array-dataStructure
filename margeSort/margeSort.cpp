#include <iostream>
using namespace std;

void marge(int arr[], int first, int mid, int last)
{
    // cout << first << mid << last << "";
    int n1 = mid - first + 1;
    int n2 = last - mid;
    int arr1[n1]; // 3
    int arr2[n2]; // 2
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[first + i]; // 3 4 1
    }

    for (int j = 0; j < n2; j++)
    {
        arr2[j] = arr[mid + 1 + j]; // 9 2
    }

    int i = 0; // 0 ,1 , 2 3
    int j = 0;
    int k = first;
    while (i < n1 && j < n2) // 3 ,2  [2]
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    } // 3 , 4 , 1  ,
    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    } // 3,4, 1,9,2
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

void margeSort(int arr[], int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;

        margeSort(arr, first, mid);
        margeSort(arr, mid + 1, last);

        marge(arr, first, mid, last);
    }
}

int main()
{
    // 3 4 1 9 2
    cout << "Inter size of array :";
    int n;
    cin >> n;
    cout << "Inter array element :";
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    margeSort(arr, 0, n);
    printArray(arr, n);

    return 0;
}