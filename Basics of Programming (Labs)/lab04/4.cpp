#include <iostream>
#include <cmath>
using namespace std;
int fact(int x){
    if(x == 0)
        return 1;
    else
        return fact(x - 1) * x;
}
int main(){
    int a;
    cin >> a;
    cout << fact(a);
    return 0;
}
