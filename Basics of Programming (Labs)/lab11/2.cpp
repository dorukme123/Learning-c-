#include<string>
#include <iostream>
using namespace std;
class shapes {
public:
	int square;
	int rectanglea, rectangleb;
	void setSquare(int square) {
		this->square = square;
	}
	void setRectangle(int reca, int recb) {
		rectanglea = reca;
		rectangleb = recb;
	}
	int getSquare() {
		return square;
	}
	int getRectangleA() {
		return rectanglea;
	}
	int getRectangleB() {
		return rectangleb;
	}
};
class areasquare :public shapes {
public:
	int squareArea() {
		return getSquare() * getSquare();
	}
};
class arearectangle :public shapes {
public:
	int rectangleArea() {
		return getRectangleA() * getRectangleB();
	}
};
int main() {
	areasquare s;
	int x, a, b;
	cout << "Set the number of square border: ";
	cin >> x;
	s.setSquare(x);
	int square_area = s.squareArea();

	arearectangle r;
	cout << "Set the number of rectangle borderA: ";
	cin >> a;
	cout << "Set the number of rectangle borderB: ";
	cin >> b;
	r.setRectangle(a, b);
	int rectangle_area = r.rectangleArea();
	cout << "Area of square is: " + to_string(square_area) + "\nArea of rectangle is: " + to_string(rectangle_area) << endl;
	system("pause");
	return 0;
}