#include <iostream>
using namespace std;

bool match(string &input)
{
    cout << input << endl;
    int state = 0;

    for (char ch : input)
    {
        switch (state)
        {
        case 0:
            if (ch == 'a')
            {
                state = 1;
            }
            else
            {
                state = 0;
            }
            break;
        case 1:
            if (ch == 'b')
            {
                state = 2;
            }
            else if (ch == 'd')
            {
                state = 3;
            }
            else
            {
                state = 0;
            }
            break;
        case 2:
            if (ch == 'c')
            {
                state = 1;
            }
            else
            {
                state = 0;
            }
            break;
        case 3:
            if (ch == 'e')
            {
                state = 4;
            }
            else
            {
                state = 0;
            }
            break;
        }
    }
    return (state == 4);
}

int main()
{
    // a(bc)*de ;

    string expression = "a(bc)*de";
    string input;
    cin >> input;

    if (match(input))
    {
        cout << "valid" << endl;
    }
    else
    {
        cout << "not valid" << endl;
    }
}