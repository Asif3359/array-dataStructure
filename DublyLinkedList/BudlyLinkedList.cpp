#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class LinkedList
{
private:
    Node *head;
    Node *temp;

public:
    LinkedList()
    {
        head = nullptr;
        temp = nullptr;
    }

    Node *getHead()
    {
        return head;
    }

    void CreatNode(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;

        if (head == nullptr)
        {

            head = newNode;
            temp = newNode;
            head->next = nullptr;
            head->prev = nullptr;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
            temp->next =nullptr;
        }
    }
};

main()
{
    LinkedList list;

    list.CreatNode(1);
    list.CreatNode(2);
    list.CreatNode(3);
    list.CreatNode(4);
    list.CreatNode(5);

    Node *current = list.getHead();

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}