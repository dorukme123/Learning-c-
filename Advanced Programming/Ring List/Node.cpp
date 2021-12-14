#include "Node.h"
using namespace std;
Node::Node()
{
}
Node::Node(string name,int val)
{
	this->name=name;
	this->val=val;
	next=NULL;  		
}
void Node::setNext(Node *x)
{
	next=x;
}
Node *Node::getNext()
{
	return next;
}
void Node::setName(string name)
{
	this->name=name;
}
string Node::getName()
{
	return name;
}
void Node::setVal(int val)
{
	this->val=val;
}
int Node::getVal()
{
	return val;
}
bool operator > (Node n1,Node n2)
{
    return n1.getVal()>n2.getVal();
}
bool operator < (Node n1,Node n2)
{
    return n1.getVal()<n2.getVal();
}
bool operator >=(Node n1,Node n2)
{
    return n1.val>=n2.val;
}
bool operator <= (Node n1,Node n2)
{
    return n1.val<=n2.val;
}
bool operator == (Node n1,Node n2)
{
    return n1.val==n1.val;
}
bool operator != (Node n1,Node n2)
{
    return n1.val!=n2.val;
}


