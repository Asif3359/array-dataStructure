#include <iostream>
using namespace std;

void marge(int arr[], int first, int mid, int last)
{
    // cout << first << mid << last << "";
    int n1 = mid - first + 1;
    int n2 = last - mid;
    int arr1[n1];
    int arr2[n2];
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[first + i];
    }

    for (int j = 0; j < n2; j++)
    {
        arr2[j] = arr[mid + 1 + j];
    }

    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << "";
    }
    cout << endl;
    for (int j = 0; j < n2; j++)
    {
        cout << arr2[j] << "";
    }
}

void margeSort(int arr[], int first, int last)
{
    int mid;
    if (first < last)
    {
        mid = first + (last - first) / 2;

        margeSort(arr, first, mid);
        margeSort(arr, mid + 1, last);

        marge(arr, first, mid, last);
    }
}

int main()
{
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

    return 0;
}