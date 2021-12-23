#include<string>
#include <iostream>
using namespace std;
class Person {
public:
	string name, surname, address;
	Person();
	~Person();
	void print() {
		cout << "Name: " + name + " Surname: " + surname + " Address: " + address << endl;
	}
	void setNameSurnameAddress(string name, string surname, string address) {
		this->name = name;
		this->surname = surname;
		this->address = address;
	}
	string getName() {
		return name;
	}
	string getSurname() {
		return surname;
	}
	string getAddress() {
		return address;
	}
};
Person::Person() {

}
Person::~Person() {

}
class hair :public Person {
public:
	string haircolor;
};
class eye :public Person {
public:
	string eyecolor;
};
class height :public Person {
public:
	string height;
};
class weight :public Person {
public:
	string weight;
};
int main()
{
	string ha, ey, heig, weig;
	hair h;
	eye e;
	height he;
	weight w;
	cout << "Write the hair color: ";
	cin >> ha;
	cout << "Write the eye color: ";
	cin >> ey;
	cout << "Write the height: ";
	cin >> heig;
	cout << "Write the weight: ";
	cin >> weig;
	h.haircolor = ha;
	e.eyecolor = ey;
	he.height = heig;
	w.weight = weig;
	cout << "Hair color: " + h.haircolor << endl;
	cout << "Eye color: " + e.eyecolor << endl;
	cout << "Height: " + he.height << endl;
	cout << "Wight: " + w.weight << endl;
	system("pause");
	return 0;
}
