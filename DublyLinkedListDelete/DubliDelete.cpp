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
        count++;
    }

    void deleteFirst()
    {

        temp = head;
        head = head->next;
        head->prev = nullptr;
        free(temp);
        count--;
    }

    void deleteLast()
    {
        temp = head;
        if (head == nullptr)
        {
            cout << "No item" << endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp = temp->prev;
        temp->next = nullptr;
        free(temp->next);

        count--;
    }
    void deleteAtPosition(int position)
    {
        if (head == nullptr)
        {
            // Empty list, nothing to delete
            return;
        }

        if (position == 1)
        {
            // Special case: deleting the head node
            temp = head;
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        Node *current = head;
        int currentPosition = 1;

        while (currentPosition < position && current != nullptr)
        {
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr)
        {
            // Position is greater than the number of nodes in the list
            return;
        }

        // Adjust pointers to skip the node at the specified position
        current->prev->next = current->next;

        if (current->next != nullptr)
        {
            current->next->prev = current->prev;
        }

        // Delete the node at the specified position
        delete current;
    }
};

int main()
{
    dublyDelete list;

    list.creatNode(1);
    list.creatNode(2);
    list.creatNode(10);
    list.creatNode(3);
    list.creatNode(4);
    list.creatNode(5);

    list.deleteFirst();
    // list.deleteLast();

    list.deleteAtPosition(3);

    Node *current = list.getHead();

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}