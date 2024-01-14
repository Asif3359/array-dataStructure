#include <iostream>

using namespace std;

int count;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class dublyDelete
{
private:
    Node *head;
    Node *temp;

public:
    dublyDelete()
    {
        head = nullptr;
        temp = nullptr;
    }
    Node *getHead()
    {
        return head;
    }

    void creatNode(int value)
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
    }

    void deleteFirst()
    {

        temp = head;
        head = head->next;
        head->prev = nullptr;
        free(temp);
    }

    void deleteLast()
    {
        temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp = temp->prev;
        temp->next = nullptr;
        free(temp->next);
    }
};

int main()
{
    dublyDelete list;

    list.creatNode(1);
    list.creatNode(2);
    list.creatNode(3);
    list.creatNode(4);
    list.creatNode(5);

    list.deleteFirst();
    list.deleteLast();

    Node *current = list.getHead();

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}