#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class DelateList
{
private:
    Node *head;
    Node *temp;

public:
    DelateList()
    {
        head = nullptr;
        temp = nullptr;
    }
    Node *getData()
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

    void deleteFirst()
    {
        Node *newNode = new Node;
        if (head == nullptr)
        {
            cout << "This List Is Empty " << endl;
            return;
        }
        else
        {
            newNode = head;
            head = newNode->next;
            free(newNode);
        }
    }
    void deleteLast()
    {
        Node *newNode = new Node;
        if (head == nullptr)
        {
            cout << "This List Is Empty " << endl;
            return;
        }
        else
        {
            temp = head;
            while (temp->next != nullptr)
            {
                newNode = temp;
                temp = temp->next;
            }
            newNode->next = nullptr;
            free(temp);
        }
    }
};

int main()
{
    DelateList list;

    list.createNode(1);
    list.createNode(2);
    list.createNode(3);
    list.createNode(4);
    list.createNode(5);

    list.deleteFirst();

    list.deleteLast();

    Node *current = list.getData();

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}