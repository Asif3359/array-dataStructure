#include <iostream>

using namespace std;

void Swap (int *a , int *b)
{
    int temp = *a ;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
        {
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[low], &arr[j]);

    return j;
}

void QuickSort ( int arr [] , int low , int high)
{
    if(low < high)
    {
        int pvot = Partition (arr , low , high);

        QuickSort(arr , low , pvot);
        QuickSort(arr , pvot+1 , high);

    }
}

int main()
{
    cout << "Enter Size of Array" << ": ";
    int n ;
    cin >> n ;
    int arr[n];
    cout << "Enter Array Element"<<": ";
    for (int i= 0 ; i<n ; i++)
    {
        cin>> arr[i];
    }

    QuickSort(arr , 0 , n);

    cout << endl;
    cout << "After Sorted :"<<"";
    for (int i= 0 ; i<n ; i++)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;
    return 0;
}
