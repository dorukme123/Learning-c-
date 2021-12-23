#include<iostream>
#include<string>
class Arr {
public:
	Arr();
	~Arr();
	int length;
	int* array1 = new int[length];
	int* array2 = new int[length];
	int* result = new int[length];
	bool which = false;
	void calculate(int arr1[], int arr2[], int x, int y, std::string text) {
		int count;
		this->array1 = arr1;
		this->array2 = arr2;
		if (x <= y) {
			count = x;
			which = true;
		}
		else {
			count = y;
		}
		int i = 0;
		for (i = 0; i < count; i++) {
			if (text == "plus") { result[i] = array1[i] + array2[i]; }
			if (text == "minus") { result[i] = array1[i] - array2[i]; }
			if (text == "multiply") { result[i] = array1[i] * array2[i]; }
			std::cout << result[i] << std::endl;
		}
		//i = i + 1;
		if (which == false) {
			for (i = i; i < x; i++) {
				result[i] = array1[i];
			}
		}
		else {
			for (i = i; i < y; i++) {
				result[i] = array2[i];
				std::cout << result[i] << std::endl;
			}
		}

		
		
	}


};
Arr::Arr() {
	//constructor
}
Arr::~Arr() {
	//destructor
}
int main() {
	int a, b, c, d;
	int x, y, z;
	std::string text = "";
	Arr ar;
	std::cout << "Set the first number of arr1: ";
	std::cin >> x;
	std::cout << "Set the second number of arr1: ";
	std::cin >> y;
	std::cout << "Set the third number of arr1: ";
	std::cin >> z;
	std::cout << "Set the first number of arr2: ";
	std::cin >> a;
	std::cout << "Set the second number of arr2: ";
	std::cin >> b;
	std::cout << "Set the third number of arr2: ";
	std::cin >> c;
	std::cout << "Set the fourth number of arr2: ";
	std::cin >> d;
	std::cout << "Set the operation[minus/plus/multiply]: ";
	std::cin >> text;

	int arr1[] = { x,y,z };
	int s1 = sizeof(arr1) / sizeof(arr1)[0];
	int arr2[] = { a,b,c,d };
	int s2 = sizeof(arr2) / sizeof(arr2)[0];
	
	std::cout << "Resulting of array indexes" << std::endl;
	ar.calculate(arr1, arr2, s1, s2, text);

	
	system("pause");

	return 0;
}