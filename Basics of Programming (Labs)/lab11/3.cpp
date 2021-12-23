#include<string>
#include <iostream>
using namespace std;
class graduate {
public:
	string name, surname;
	void setName(string name) {
		this->name = name;
	}
	void setSurname(string surname) {
		this->surname = surname;
	}
	string getName() {
		return name;
	}
	string getSurname() {
		return surname;
	}
};
class undergraduate :public graduate {
public:
	string educational_level = "undergraduate";
};
class postgraduate :public graduate {
public:
	string educational_level = "postgraduate";
};
int main() {
	string a, b, c, d;
	
	undergraduate u;
	cout << "Set the name of undergraduate person: ";
	cin >> a;
	u.setName(a);
	cout << "Set the surname of undergraduate person: ";
	cin >> b;
	u.setSurname(b);
	postgraduate p;
	cout << "Set the name of postgraduate person: ";
	cin >> c;
	p.setName(c);
	cout << "Set the surname of postgraduate person: ";
	cin >> d;
	p.setSurname(d);
	cout << "Undergraduate student credentials:\n";
	cout << "Name: " + u.getName() + "\nSurname: " + u.getSurname() << endl;
	cout << "Postgraduate student credentials:\n";
	cout << "Name: " + p.getName() + "\nSurname: " + p.getSurname() << endl;
	system("pause");
	return 0;
}