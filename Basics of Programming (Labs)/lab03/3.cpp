#include <iostream>
#include <cmath>
using namespace std;
float len(float x1, float y1, float x2, float y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int main(){
    int x, y, xx, yy;
    cin >> x >> y >> xx >> yy;
    cout << len(x, y, xx, yy);
    return 0;
}