#include <iostream>
#include <string>
using namespace std;
class Volume {
public:
	static int result;
	static int height;
	static int width;
	static int lenght;
	Volume(int a, int b, int c) {
		//constructor
		height = a;
		width = b;
		lenght = c;
		result = height * width * lenght;
	}
	~Volume();
};
int Volume::height = 0;
int Volume::width = 0;
int Volume::lenght = 0;
int Volume::result = 0;
Volume::~Volume() {
	//destructor 
}

int main() {
	int x, y, z;
	cout << "Enter the height: ";
	cin >> x;
	cout << "Enter the width: ";
	cin >> y;
	cout << "Enter the lenght: ";
	cin >> z;
	Volume v(x, y, z);
	std::cout << "Calculated volume is: "+to_string(v.result) << std::endl;
	system("pause");
	return 0;
}