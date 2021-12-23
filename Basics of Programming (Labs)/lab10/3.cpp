#include <iostream>

using namespace std;
class ComplexNumber{
	int reel_part, virtual_part;
public:
	ComplexNumber(int, int);
	ComplexNumber operator + (const ComplexNumber&);
	ComplexNumber operator - (const ComplexNumber&);
	ComplexNumber operator * (const ComplexNumber&);
	ComplexNumber&operator = (const ComplexNumber&);
	friend ostream& operator << (ostream&, const ComplexNumber&);
};

ComplexNumber::ComplexNumber(int reel = 0, int sanal = 0)
{
	reel_part = reel;
	virtual_part = sanal;
}

ComplexNumber ComplexNumber::operator + (const ComplexNumber& k)
{
	int reel, sanal;
	reel = reel_part + k.reel_part;
	sanal = virtual_part + k.virtual_part;
	return ComplexNumber(reel, sanal);
}

ComplexNumber ComplexNumber::operator - (const ComplexNumber& k)
{
	int reel, sanal;
	reel = reel_part - k.reel_part;
	sanal = virtual_part - k.virtual_part;
	return ComplexNumber(reel, sanal);
}

ComplexNumber ComplexNumber::operator * (const ComplexNumber& k)
{
	int reel, sanal;
	reel = reel_part * k.reel_part;
	sanal = virtual_part * k.virtual_part;
	return ComplexNumber(reel, sanal);
}


ComplexNumber& ComplexNumber::operator = (const ComplexNumber& k)
{
	reel_part = k.reel_part;
	virtual_part = k.virtual_part;
	return *this;
}

ostream& operator << (ostream& output, const ComplexNumber& k)
{
	output << "(" << k.virtual_part << "+" << k.reel_part << "i)" << endl;
	return output;
}

int main()
{
	int a, b, c, d;
	cout << "Set the reel number for first complex number: ";
		cin >> a;
		cout << "Set the virtual number for first complex number: ";
		cin >> b;
		cout << "Set the reel number for second complex number: ";
		cin >> c;
		cout << "Set the virtual number for second complex number: ";
		cin >> d;
	ComplexNumber ks1(b, a), ks2(d, c), ks3;
	int opt;
	cout << "=Plus,Minus and Multiply operations in Complex Number=\n" << endl;
	cout << "Complex number 1:" << ks1;
	cout << "Complex number 2:" << ks2;
	cout << "--------------------" << endl;
	cout << "(1) - Plus Operation" << endl;
	cout << "(2) - Minus Operation" << endl;
	cout << "(3) - Multiply Operation" << endl;
	cout << "--------------------" << endl;
	cout << "Choose the option that you want to see result";
	cin >> opt;

	if (opt == 1)
	{
		ks3 = ks1 + ks2;
		cout << "\nResulting of Plus Operation:" << ks3 << endl;
	}

	else if (opt == 2)
	{
		ks3 = ks1 - ks2;
		cout << "\nResulting of Minus Operation:" << ks3 << endl;
	}

	else if (opt == 3)
	{
		ks3 = ks1 * ks2;
		cout << "\nResulting of Multiply Operation:" << ks3 << endl;
	}

	else
	{
		cout << "\nThere is no option like that!" << endl;
	}
	system("PAUSE");
	return 0;
}