#include <string>
using namespace std;
class Node
{
	private:
		string name;
		int val; 
		class Node* next;
  	public:
  		Node();
  		Node(string name,int val);
		void setNext(Node *x);
		Node *getNext();
		void setName(string name);
		string getName();
		void setVal(int val);
		int getVal();
		friend bool operator > (Node n1,Node n2);
		friend bool operator < (Node n1,Node n2);
		friend bool operator >=(Node n1,Node n2);
		friend bool operator <= (Node n1,Node n2);
    	friend bool operator == (Node n1,Node n2);
		friend bool operator != (Node n1,Node n2);
};

