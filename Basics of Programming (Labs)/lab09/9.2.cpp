#include<iostream>
#include<string>
using namespace std;
class Temperature {
public:
	int F;
	int C;
	Temperature();
	~Temperature();
	double fahrenheitToCelsius(double fahrenheit)
	{
		double celsius;

		celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
		return celsius;
	}
};
Temperature::Temperature() {
	//constructor
}
Temperature::~Temperature() {
	//destructor
}
int main() {
	int x;
	Temperature t;
	cout << "Enter the Fahreneit Degree: ";
	cin >> x;

	std::cout << "Fahrenheit to Celsius: " + to_string(t.fahrenheitToCelsius(x)) << std::endl;
	system("pause");
	return 0;
}