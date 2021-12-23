#include<iostream>
#include<string>
class Point {
private:
	int x, y;

public:
	Point();
	~Point();
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int* PlusAndMinus() {
		int plus = getX() + getY();
		int minus1 = getY() - getX();
		int minus2 = getX() - getY();
		int r[3];
		r[0] = plus; r[1] = minus1; r[2] = minus2;
		return r;
	}


};
Point::Point() {
	//constructor
}
Point::~Point() {
	//destructor
}
int main() {
	Point t;
	int x, y;
	std::cout << "Set a X number: ";
	std::cin >> x;
	std::cout << "Set a Y number: ";
	std::cin >> y;
	t.setX(x);
	t.setY(y);
	std::string text = "X + Y = " + std::to_string(t.PlusAndMinus()[0]) + " , " + "X - Y = " + std::to_string(t.PlusAndMinus()[1]) + " , " + "Y - X = " + std::to_string(t.PlusAndMinus()[2]);
	std::cout << text << std::endl;
	system("pause");
	return 0;
}