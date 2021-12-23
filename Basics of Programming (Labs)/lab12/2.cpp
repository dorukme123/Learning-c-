#include <iostream>
#include <string>
using namespace std;
class Data {
public:
    int value;
    Data();
    ~Data();
    void DataSize() {
        cout << "Data size: " + to_string(sizeof(value)) << endl;
    }
};
Data::Data() {

}
Data::~Data() {

}
class Takeown :public Data {
public:
    Takeown();
    void DataType() {
        cout << "Data type: ";
        cout << typeid(value).name() << endl;
    }
};
Takeown::Takeown() {

}
int main()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;
    Takeown t;
    Data d;
    d.value = x;

    d.DataSize();
    t.DataType();
    system("pause");
    return 0;
}

