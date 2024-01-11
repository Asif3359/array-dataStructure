#include <iostream>
using namespace std;

void binarySearch(int array[], int n, int k)
{
    int start = 0;
    int end = n-1;
    int mid;
    while (start < end)
    {
        mid = (start + end) / 2;
        if (array[mid] == k)
        {
            cout << "Found " << endl;
            return;
        }
        else if (array[mid] < k)
        {
            start = mid + 1;
            mid = (start + end) / 2;
        }
        else if (array[mid] > k)
        {
            end = mid - 1;
            mid = (start + end) / 2;
        }
    }
    cout << "not Found"<<endl;
}

int main()
{
    // implement Binary search
    int array[100];
    int n;
    cout << "Enter size of array " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int k;
    cout << "Enter key " << endl;
    cin >> k;
    binarySearch(array, n, k);

    return 0;
}
