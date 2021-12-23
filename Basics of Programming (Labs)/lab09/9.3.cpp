#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class Point {
public:
	int x1, x2, y1, y2;
	Point();
	~Point();
	void print() {
		std::string text = "First dot: (" + std::to_string(x1) + "," + std::to_string(x2) + "), Second dot: (" + std::to_string(y1) + "," + std::to_string(y1) + ")";
		std::cout << text << std::endl;
	}
	float distance() {
		float root = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		return root;
	}

};
Point::Point() {
	//constructor
}
Point::~Point() {
	//destructor
}
int main() {
	int a, b, c, d;

	Point t;

	cout << "Enter the dot of x1: ";
	cin >> a;
	cout << "Enter the dot of x2: ";
	cin >> b;
	cout << "Enter the dot of y1: ";
	cin >> c;
	cout << "Enter the dot of y2: ";
	cin >> d;
	t.x1 = a;
	t.x2 = b;
	t.y1 = c;
	t.y2 = d;
	t.print();
	std::string dist = "Distance between 2 dots: " + std::to_string(t.distance());
	std::cout << dist << std::endl;
	system("pause");
	return 0;
}