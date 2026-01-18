/*
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

class MyLinkedList
{
public:
    Node *head;
    int size;

    MyLinkedList() : head(nullptr), size(0) {}

    int get(int index)
    {
        if (index >= size || index < 0)
        {
            return -1;
        }
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current->val;
    }

    void addAtHead(int val) { addAtIndex(0, val); }

    void addAtTail(int val) { addAtIndex(size, val); }

    void addAtIndex(int index, int val)
    {
        if (index > size || index < 0)
        {
            return;
        }

        Node *current = head;
        Node *newNode = new Node(val);

        if (index == 0)
        {
            newNode->next = current;
            head = newNode;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }

        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0)
        {
            return;
        }

        if (index == 0)
        {
            Node *nextNode = head->next;
            delete head;
            head = nextNode;
        }
        else
        {
            Node *current = head;

            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }

            Node *nextNode = current->next->next;
            delete current->next;
            current->next = nextNode;
        }

        size--;
    }

    ~MyLinkedList()
    {
        Node *p = head;

        while (head)
        {
            head = head->next;
            delete p;
            p = head;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    MyLinkedList myLinkedList = new MyLinkedList();
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2); // linked list becomes 1->2->3
    myLinkedList.get(1);           // return 2
    myLinkedList.deleteAtIndex(1); // now the linked list is 1->3
    myLinkedList.get(1);           // return 3
    return 0;
}