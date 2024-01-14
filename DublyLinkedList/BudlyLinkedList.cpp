#include <iostream>

using namespace std;

int count;
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
            temp->next = nullptr;
        }
        count++;
    }
    void insertFirst(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;

        newNode->next = head;
        newNode->prev = nullptr;
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
        temp->prev = temp;

        count++;
    }
    void insertAnyPosition(int value, int poss)
    {
        Node *newNode = new Node;

        if (count < poss)
        {
            cout << " your position is not valid" << endl;
            return;
        }
        else
        {
            newNode->data = value;
            newNode->next = nullptr;
            temp = head;
            int i = 1;
            while (i < poss)
            {
                temp = temp->next;
                i++;
            }
            newNode->next = temp->next ;
            temp->next = newNode;
            temp->prev = temp;
            count++;
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

    list.insertFirst(10);

    list.insertLast(20);
    list.insertAnyPosition(30, 3);

    Node *current = list.getHead();

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}