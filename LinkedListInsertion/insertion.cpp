#include <iostream>

using namespace std;

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
    }

    void insertFirst(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
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

    Node *CurentNode = list.getHead();

    while (CurentNode != nullptr)
    {
        cout << CurentNode->data << " ";
        CurentNode = CurentNode->next;
    }

    while (CurentNode != nullptr)
    {
        cout << CurentNode->data << " ";
        CurentNode = CurentNode->next;
    }

    return 0;
}