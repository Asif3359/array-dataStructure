#include <iostream>

using namespace std;
int count;
struct Node
{
    int data;
    Node *next;
};

class Insertion
{
private:
    Node *head;
    Node *temp;

public:
    Insertion()
    {
        head = nullptr;
        temp = nullptr;
    }
    Node *getHead()
    {
        return head;
    }

    void createNode(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        count++;
    }

    void insertFirst(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        count++;
    }
    void insertLast(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        count++;
    }

    void insertAny(int value, int pos)
    {
        Node *newNode = new Node;
        newNode->data = value;
        if (pos > count)
        {
            cout << "this Position is not Valid" << endl;
            return;
        }
        else
        {
            int i = 1;
            temp = head;
            while (i <= pos)
            {
                temp = temp->next;
                i++;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        count++;
    }

    void getLength()
    {
        int i = 1;
        temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
            i++;
        }
        cout << "Length of this List :" << i << endl;
    }
};

int main()
{
    Insertion list;

    list.createNode(1);
    list.createNode(2);
    list.createNode(3);
    list.createNode(4);

    list.insertFirst(10);

    list.insertLast(20);

    list.insertAny(30, 2);

    list.getLength();

    Node *CurentNode = list.getHead();

    while (CurentNode != nullptr)
    {
        cout << CurentNode->data << " ";
        CurentNode = CurentNode->next;
    }

    cout << endl;
    cout << count << endl;

    return 0;
}