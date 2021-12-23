#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    };

void readList(Node* n)
{
    while (n != NULL){
        cout << "{ "<< n->data << " " << "}";
        n = n->next;
        }
    }
void addBegin(Node** headRef, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}
void addEnd(Node** headRef, int newData)
{
    Node* newNode = new Node();
    Node *last = *headRef;
    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
        last->next = newNode;
    return;
}
void addAfter(Node* prevNode, int newData)
{
    if (prevNode == NULL)
    {
        cout<<"error";
        return;
    }
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}
void addBefore(Node* givPtr, int numb)
{
    if (Node* head = NULL) {
        Node* newNode = new Node();
        Node* n = newNode;
        n->next = head;
        head = n;
        return;
    }
    else {
        Node* newNode = new Node();
        Node *p, *n = head;
        for (n, p; n != givPtr; p = n, n = n->next);
        Node* m = newNode;
        m->next = p->next;
        p->next = m;
        return;
    }
}
void deleteGiven(Node** headRef, int numb)
{

    Node* temporary = *headRef;
    Node* prev = NULL;

    if (temporary != NULL && temporary->data == numb)
    {
        *headRef = temporary->next;
        delete temporary;
        return;
    }

      else
    {
    while (temporary != NULL && temporary->data != numb)
    {
        prev = temporary;
        temporary = temporary->next;
    }

    if (temporary == NULL)
        return;
    prev->next = temporary->next;
    delete temporary;
    }
}

int main()
{
    Node* head = NULL;

    head = new Node();
    readList(head);
    cout << "stop\n";
    addBegin(&head, 7);
    addBegin(&head, 5);
    addBegin(&head, 9);
    addBegin(&head, 1);
    addBegin(&head, 3);
    readList(head);
    cout << "stop\n";
    addEnd(&head, 8);
    readList(head);
    cout << "stop\n";
    addAfter(head->next, 4);
    readList(head);
    cout << "stop\n";

    deleteGiven(&head, 2);
    readList(head);
    cout << "stop\n";


    return 0;
}
