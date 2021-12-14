#include "circle_list.h"
#include <iostream>
using namespace std;
circle_list::circle_list()
{
    head = NULL;
    position = NULL;
    count = 0;
    go_first();
} 
circle_list::~circle_list()
{
    while(count!=1)
    	del_next();
}
void circle_list::insert(string name, int val)
{
    Node* new_node = new Node(name,val);
    go_last();
    if(position != NULL&& head!=NULL)
	{
        new_node->setNext(position->getNext());
        position->setNext(new_node);
    }
	else
	{
        new_node->setNext(new_node);
        position = head = new_node;
    }
    count++;
} 
void circle_list::del_next()
{
    go_last();  
    if (position != NULL && head!=NULL)
	{
        Node* tmp = position;
        position->setNext(position->getNext()->getNext());
        if(tmp == head) 
			head = tmp->getNext();
        delete tmp;
    }
    count--;
} 
void circle_list::go_next()
{
    if (position != NULL && head!=NULL)
        position = position->getNext();
}
void circle_list::right()
{
    if (head != NULL)
        head = head->getNext();
}
void circle_list::left()
{
    if (head != NULL)
    {
    	go_last();
    	head = position;
	}        
}
void circle_list::go_last()
{
	if (head != NULL)
	{
		go_first();
	    for(int i=0;i<count-1;i++)
	        go_next();
    }
} 
void circle_list::go_first()
{
    position = head;
} 
void circle_list::show()
{
	go_first();    
	for(int i = 0;i<size();i++)
	{
	    cout<<"Название - "<<position->getName()<<" Значение - "<<position->getVal() <<endl;
	    go_next();
	}
} 
int circle_list::size()
{
    return count;
}
void circle_list::sort_alphabet()
{
	Node* a, *b, *p, *h = NULL;
    go_last();
    position->setNext(NULL);
    for(Node* i = head; i != NULL; )
	{
        a = i;
        i = i->getNext();
        b = h;
        for(p = NULL; (b != NULL) && (a->getName() > b->getName()); )
		{
            p = b;
            b = b->getNext();
        }
        if(p == NULL)
		{
            a->setNext(h);
            h = a;
        } 
		else
		{
            a->setNext(b);
            p->setNext(a);
        }
    }
    if(h != NULL) 
        head = h;
    go_first();
    while(position->getNext()!=NULL)
    	position=position->getNext();
	position->setNext(head);
}
void circle_list::sort_DESC()
{
    Node* a, *b, *p, *h = NULL;
    go_last();
    position->setNext(NULL);
    for(Node* i = head; i != NULL; )
	{
        a = i;
        i = i->getNext();
        b = h;
        for(p = NULL; (b != NULL) && (*a< *b); )
		{
            p = b;
            b = b->getNext();
        }
        if(p == NULL)
		{
            a->setNext(h);
            h = a;
        } 
		else
		{
            a->setNext(b);
            p->setNext(a);
        }
    }
    if(h != NULL) 
        head = h;
    go_first();
    while(position->getNext()!=NULL)
    	position=position->getNext();
	position->setNext(head);
}
void circle_list::sort_ASC()
{
    Node* a, *b, *p, *h = NULL;
    go_last();
    position->setNext(NULL);
    for(Node* i = head; i != NULL; )
	{
        a = i;
        i = i->getNext();
        b = h;
        for(p = NULL; (b != NULL) && (*a > *b); )
		{
            p = b;
            b = b->getNext();
        }
        if(p == NULL)
		{
            a->setNext(h);
            h = a;
        } 
		else
		{
            a->setNext(b);
            p->setNext(a);
        }
    }
    if(h != NULL) 
        head = h;
    go_first();
    while(position->getNext()!=NULL)
    	position=position->getNext();
	position->setNext(head);
}

