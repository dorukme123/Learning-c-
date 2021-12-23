#include <iostream>
#include <cmath>
using namespace std;
int line(int n){
    if (n == 1)
        return 1;
    return line(n - 1) + n;
}
int main(){
    int a;
    cin >> a;
    cout << line(a);
    return 0;
}