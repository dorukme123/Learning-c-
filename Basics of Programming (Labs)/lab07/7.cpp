#include <iostream> 
#include <stack> 
#include <string>
#define MAX_SIZE 8
using namespace std;

int main()
{
    stack<int> stack;
    typedef int number;
    number n1;
    number n2;
    cout << "Enter a number: ";
    cin >> n1;
    cout << "Enter a number: ";
    cin >> n2;
    number n3 = MAX_SIZE;
    cout << "Adding the number " + to_string(n1) +" into stack\n";
    stack.push(n1); //add 
    cout << "Adding the number " +to_string( n2) + " into stack\n";
    stack.push(n2); // add
    cout << "Adding the number " + to_string(n3) + " into stack\n";
    stack.push(n3); // add 8
    cout << "Extracting the number " + to_string(n3) + " from stack\n";
    stack.pop(); // extract 8
    cout << "Show the toppest number in stack " + to_string(stack.top()) << endl;;
    system("pause");
}
