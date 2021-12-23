#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;
struct stack
{
    int maxsize;
    int top;
    int* items;
};


struct stack* newStack(int capacity)
{
    struct stack* pt = (struct stack*)malloc(sizeof(struct stack));

    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);

    return pt;
}


int size(struct stack* pt)
{
    return pt->top + 1;
}


int isEmpty(struct stack* pt)
{
    return pt->top == -1;
}


int isFull(struct stack* pt)
{
    return pt->top == pt->maxsize - 1;
}


void push(struct stack* pt, int x)
{

    if (isFull(pt))
    {
        printf("OverFlow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    printf("Inserting %d\n", x);


    pt->items[++pt->top] = x;
}


int peek(struct stack* pt)
{

    if (!isEmpty(pt))
        return pt->items[pt->top];
    else
        exit(EXIT_FAILURE);
}


int pop(struct stack* pt)
{

    if (isEmpty(pt))
    {
        printf("UnderFlow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    printf("Removing %d\n", peek(pt));


    return pt->items[pt->top--];
}

int main()
{
    int x;
    string name;
    cout << "Enter the stack size: ";
    cin >> x;
    struct stack* pt = newStack(x);
    while (true) {
        cout << "Write the method: [push\\pop\\peek\\quit]\n";
        cin >> name;
        if (name == "push") {
            cout << "Enter the number that you want to push into stack: ";
            cin >> x;
            push(pt, x);
        }
        if (name == "pop") {
            cout << "Pop the element from stack:" + pop(pt);
        }
        if (name == "peek") {
            printf("Top element is %d\n", peek(pt));
        }
        if (name == "quit") {
            break;
        }
    }
    system("pause");
    return 0;
}

