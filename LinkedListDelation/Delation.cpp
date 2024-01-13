#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

int count;

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
        count++;
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
        count--;
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
        count--;
    }
    void deleteAny(int pos)
    {
        Node *newNode = new Node;

        if (pos > count)
        {
            cout << "your position is not valid " << endl;
            return;
        }
        else
        {
            if (head == nullptr)
            {
                cout << "This List Is Empty " << endl;
                return;
            }
            else
            {
                temp = head;
                int i = 1;
                while (i < pos)
                {
                    newNode = temp;
                    temp = temp->next;
                    i++;
                }
                newNode->next = temp->next;
                free(temp);
            }
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

    list.deleteAny(2);

    Node *current = list.getData();

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}