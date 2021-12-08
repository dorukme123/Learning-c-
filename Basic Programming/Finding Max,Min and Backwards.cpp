#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cout << "enter student number: ";
    cin >> k;
    int number = k;
    int arr[10];
    for (int i = 9; i >= 0; i--) {
    arr[i] = number % 10;
    number /= 10;
}
    int n = sizeof(arr) / sizeof(arr[0]);
    int &min = *min_element(arr,arr+n );
    int &max = *max_element(arr,arr+n );
    cout << "Min= " << min;
    cout << "\nMax= " << max;
    cout << "\nstudent number backwards: ";
    for (int j = 9; j >= 0; j--){
        cout << arr[j];
    }
}
