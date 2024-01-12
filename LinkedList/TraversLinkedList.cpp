#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{

private:
    Node *head;
    Node *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList()
    {
        Node *current = head;
        Node *next;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void append(int value)
    {

        Node *newNode = new Node;

        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node *getHead() const
    {
        return head;
    }
};

int main()
{

    LinkedList list;

    int choise = 1;

    int number;
    int ch;
    for (int i = 1; i <= choise; i++)
    {
        cout << "Enter list Number  :";
        cin >> number;
        list.append(number);
        cout << "Do you want To continue 0 / 1 :";
        cin >> ch;
        if (ch == 1)
        {
            choise = choise + 1;
        }
    }

    Node *current = list.getHead();
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
    return 0;
}
