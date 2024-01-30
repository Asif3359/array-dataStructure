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
    int pivot = arr[high];
    int i = low - 1;
    int j = low;

    while (j < high)
    {
        if (arr[j] <= pivot)
        {
            i++;
            Swap(&arr[i], &arr[j]);
        }
        j++;
    }
    Swap(&arr[i + 1], &arr[high]);

    return i + 1;
}
void QuickSort ( int arr [] , int low , int high)
{
    if(low < high)
    {
        int pvot = Partition (arr , low , high);

        QuickSort(arr , low , pvot-1);
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

    QuickSort(arr , 0 , n-1);

    cout << endl;
    cout << "After Sorted :"<<"";
    for (int i= 0 ; i<n ; i++)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;
    return 0;
}

