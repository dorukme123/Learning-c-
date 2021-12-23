#include <iostream>
#include <string>
using namespace std;
class Point {
public:
    int x, y;
    Point();
    ~Point();
};
Point::Point() {

}
Point::~Point() {

}
class Inherit :public Point {
public:
    int plus(int x, int y) {
        return (x + y);
    }
    int minus(int x, int y) {
        return (x - y);
    }
};

int main()
{
    int x, y;
    Point t;
    Inherit i;
    cout << "Enter the first number: ";
    cin >> x;
    cout << "Enter the second number: ";
    cin >> y;
    t.x = 3;
    t.y = 4;
    cout << "\nPlus Result: " + to_string(i.plus(t.x, t.y)) + "\nMinus result: " + to_string(i.minus(t.x, t.y)) + "\n";
    system("pause");
    return 0;
}

