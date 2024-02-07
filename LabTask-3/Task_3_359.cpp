#include <iostream>
#include <string>

using namespace std;

class Activity {
public:
    int start;
    int finish;
    string name;

    Activity(int s, int f, string n)
    {
        start = s ;
        finish = f;
        name = n ;
    }
};

void Swap (Activity &a , Activity &b)
{
    Activity temp = a ;
    a = b ;
    b = temp ;
}

void bubbleSAort (Activity* activities, int numActivities)
{
        for (int i = 0; i < numActivities - 1; ++i)
        {
            for (int j = 0; j < numActivities - i - 1; ++j)
            {
                if (activities[j].finish > activities[j + 1].finish)
                {
                    Swap(activities[j], activities[j + 1]);
                }
            }
        }
}

void findMaxActivities(Activity* activities, int numActivities) {


    bubbleSAort(activities, numActivities);

    cout << "Selected Activities:\n";
    cout << "(" << activities[0].start << "," << activities[0].finish << ") " << activities[0].name << "\n";


    int prevFinish = activities[0].finish;
    for (int i = 1; i < numActivities; ++i)
        {

            if (activities[i].start >= prevFinish)
            {
                cout << "(" << activities[i].start << "," << activities[i].finish << ") " << activities[i].name << "\n";
                prevFinish = activities[i].finish;
            }
        }
}

int main() {

    Activity activities[] = {
        {5, 9, "A1"},
        {1, 2, "A2"},
        {3, 4, "A3"},
        {0, 6, "A4"},
        {5, 7, "A5"},
        {8, 9, "A6"}
    };
    int numActivities = sizeof(activities) / sizeof(activities[0]);

    findMaxActivities(activities, numActivities);

    return 0;
}
