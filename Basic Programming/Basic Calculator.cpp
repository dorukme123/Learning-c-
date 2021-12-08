#include <iostream>
#include <unistd.h>

using namespace std;

int addNumb(int add1,int add2){
    int result;
    result = add1 + add2;
    return result;
}

int subsNumb(int sub1,int sub2){
    int result;
    result = sub1 - sub2;
    return result;
}

int divideNumb(int div1,int div2){
    int result;
    result = div1 / div2;
    return result;
}

int multipNumb(int mul1,int mul2){
    int result;
    result = mul1 * mul2;
    return result;
}

int main(){
    unsigned int microsecond = 1000000;
    int numb1, numb2;
    cout << "Welcome to the calculator!\n";
    usleep(2 * microsecond);
    cout << "Please choose what do you want to do: \n";
    usleep(2 * microsecond);
    int startCalc = 1;
    while (startCalc = true){
        cout << endl << "|-| Add numbers: 1\n" << "|-| Substract numbers: 2\n" << "|-| Divide numbers: 3\n" << "|-| Multiply numbers: 4\n" << "|-| Close the program: 5\n";
        cout << "Enter Here: ";
        int menuChooser;
        cin >> menuChooser;
        if(menuChooser > 0 && menuChooser < 5){
        switch(menuChooser){
        case 1:
        cout << "Please enter the numbers: \n";
        cout << "Number 1: ";
        cin >> numb1;
        cout << "Number 2: ";
        cin >> numb2;
        cout << addNumb(numb1,numb2) << endl;
        usleep(2 * microsecond);
        break;
        case 2:
        cout << "Please enter the numbers: \n";
        cout << "Number 1: ";
        cin >> numb1;
        cout << "Number 2: ";
        cin >> numb2;
        cout << subsNumb(numb1,numb2) << endl;
        usleep(2 * microsecond);
        break;
        case 3:
        cout << "Please enter the numbers: \n";
        cout << "Number 1: ";
        cin >> numb1;
        cout << "Number 2: ";
        cin >> numb2;
        cout << divideNumb(numb1,numb2) << endl;
        usleep(2 * microsecond);
        break;
        case 4:
        cout << "Please enter the numbers: \n";
        cout << "Number 1: ";
        cin >> numb1;
        cout << "Number 2: ";
        cin >> numb2;
        cout << multipNumb(numb1,numb2) << endl;
        usleep(2 * microsecond);
        break;
        }}
        else {
            cout << "Closing the program!\n";
            break;
        }

    }
    return 0;

}
