#include <string>
#include <math.h>
#include <iostream>
using namespace std;
class Point { // 1.soru
public:
	int x1;
	int x2;
	int y1;
	int y2;
	float Distance() {
		float root;
		root = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		return root;
	}
};

class Point2 { // 2.soru
private:
	int x1;
	int x2;
	int y1;
	int y2;
	void setX(int x, int xx) {
		x1 = x;
		x2 = xx;
	}
	int* getX() {
		int r[2];
		r[0] = x1;
		r[1] = x2;
		return r;
	}
	void setY(int y, int yy) {
		y1 = y;
		y2 = yy;
	}
	int* getY() {
		int r[2];
		r[0] = y1;
		r[1] = y2;
		return r;
	}
	float getDistance() {
		setX(3, 7);
		setY(2, 8);
		float root = sqrt(pow((getX()[1] - getX()[0]), 2) + pow((getY()[1] - getY()[0]), 2));
		return root;
	}

};

class triangle { //3. soru
public:
	int a;
	int b;
	int c;
	void print() {
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

	}
	std::string typetriangle() {
		if ((a == 60) && (b == 60) && (c == 60)) {
			return "equilateral triangle";
		}
		if ((a == b) || (a == c) || (b == c)) {
			return "isosceles triangle";
		}
		else {
			return "scalene triangle";
		}
	}
private:
	bool istriangle() {
		if ((a + b + c) == 180) {
			return true;
		}
		else {
			return false;
		}
	}

};

int main() {
	int a, b, c, d;
		Point test;
		cout << "Enter the X1 coordinate: ";
		cin >> a;
		cout << "Enter the X2 coordinate: ";
		cin >> b;
		cout << "Enter the Y1 coordinate: ";
		cin >> c;
		cout << "Enter the Y2 coordinate: ";
		cin >> d;
	test.x1 = a;
	test.x2 = b;
	test.y1 = c;
	test.y2 = d;
	float result = test.Distance();
	std::cout << "Distance between two dots : " + to_string(result) <<std::endl;

	system("pause");

	return 0;
}





