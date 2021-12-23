#include <iostream>
using namespace std;
void swap(float *x, float *y){
    x = y;
    y = x;
}
int main(){
    float a, b;
    cin >> a >> b;
    cout << a << " " << b << endl;
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}