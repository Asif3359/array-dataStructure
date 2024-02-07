#include <iostream>

using namespace std;

class Item {
public:
    int value;
    int weight;
    double valuePerWeight;

    Item()
    {
        value = 0 ;
        weight = 0 ;
        valuePerWeight = 0.0;
    }
    Item(int v, int w) {
        value = v;
        weight = w;
        valuePerWeight = (double)value / weight;
    }
};


void swapItems(Item& a, Item& b) {
    Item temp = a;
    a = b;
    b = temp;
}


void sortItems(Item items[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (items[j].valuePerWeight < items[j + 1].valuePerWeight) {
                swapItems(items[j], items[j + 1]);
            }
        }
    }
}


double fractionalKnapsack(int capacity, Item items[], int n) {

    sortItems(items, n);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n; ++i) {

        if (remainingCapacity >= items[i].weight) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        }

        else {
            totalValue += (double)remainingCapacity / items[i].weight * items[i].value;
            break;
        }
    }

    return totalValue;
}

int main() {

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    Item *items = new Item[n];

    for (int i = 0; i < n; ++i) {
        int value, weight;
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> value >> weight;
        items[i] = Item(value, weight);
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(capacity, items, n);

    cout << "Maximum possible value = " << maxValue << endl;

    delete[] items;

    return 0;
}
