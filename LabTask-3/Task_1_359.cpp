#include <iostream>

using namespace std;

void Sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void findAndRemoveMedian(int arr[], int& size) {
    int median;
    if (size % 2 == 0) {
        median = size / 2;
        cout << "M:" <<arr[median - 1] << " ";
        for (int i = median - 1; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
    } else {
        median = size / 2;
        cout << "M:" <<arr[median] << " ";
        for (int i = median; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

int main() {
    int arr[100];
    int size = 0;
    int n;
    cout << "Enter Your Number:\n";

    while (true) {
        cin >> n;
        if (n == -1) {
            if (size > 0) {
                Sort(arr, size);
                findAndRemoveMedian(arr, size);
            }
        } else if (n == 0) {
            break;
        } else {
            arr[size++] = n;
        }
    }
    if (size > 0) {
        cout << arr[0];
    }
    return 0;
}

