#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int** read(int m,int n,char* name){
    cout << name << " : enter " << m*n << " elements\n";
    int **A = new int *[m];
    for(int i=0; i<m; i++){
        A[i]=new int[n]; // cols
        for(int j = 0; j<n; j++){
            cin>>A[i][j];
        }
    }
    return A; // matrix
}
void beep1();
void display(int **A, int m,int n,char* name){
    cout << name << " | \n";
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
void deallocate(int **A,int m){
    for(int i = 0; i<m; i++){
        delete A[i];
    }
    delete []A;
}
void dangerousStuff();
int** add(int **A,int **B,int m,int n){
    int **result=new int*[m];
    for(int i = 0; i < m; i++){
        result[i]= new int[n];
        for(int j = 0; j<n; j++){
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int** multiply(int **A,int **B,int m1,int n1,int n2){
    int **result=new int*[m1];
    for(int i=0; i<m1; i++){
        result[i] = new int[n2];
        for(int j = 0; j<n2; j++){
            result[i][j] = 0;
            for(int t = 0; t<n1; t++){
                result[i][j] += A[i][t] * B[t][j];
            }
        }
    }
    return result;
}

int** transpose(int **A,int m,int n){
    int **B=new int*[n];
    for(int i = 0; i<n; i++){
        B[i] = new int[m];
        for(int j = 0; j<n; j++){
            B[i][j]=A[j][i]; // exchange variables
        }
    }
    return B; // transpose of A[][].
}



int main()
{
   int ch=0;
   do{
    system("cls");
    cout << "\nOperations : ";
    cout << "\n 1.Addition:";
    cout << "\n 2.Multiply:";
    cout << "\n 3.Transpose:";
    cout << "\n 4.Exit:";
    cout << "\n Enter:";
    cin >> ch;
    int m1, n1, m2, n2;
    int **X, **Y, **Z;
    switch(ch){
case 1:
    cout << "Enter 1st Matrix MxN : ";
    cin>>m1>>n1;
    X=read(m1, n1,"Matrix X");
    Y=read(m1, n1,"Matrix Y");
    Z=add(X, Y, m1, n1);
    display(X, m1, n1, "Matrix X");
    display(Y, m1, n1, "Matrix Y");
    display(Z, m1, n1, "Matrix Z");
    deallocate(X, m1);
    deallocate(Y, m1);
    deallocate(Z, m1);
    break;
case 2:
    cout << "Enter 1st Matrix M*N : ";
    cin>>m1>>n1;
    X=read(m1,n1,"Matrix X");
    cout << "Enter 2nd Matrix M*N : ";
    cin>>m2>>n2;
    Y=read(m2,n2,"Matrix Y");
    if(n1==m2){
        Z=multiply(X,Y,m1,n1,n2);
        display(X, m1, n1,"Matrix X");
        display(Y, m1, n1,"Matrix Y");
        display(Z, m1, n1,"Matrix Z");
        deallocate(X,m1);
        deallocate(Y,m1);
        deallocate(Z,m1);
    }else {cout << "You have broken the rule of matrix multiplication!\n";
        deallocate(X,m1);
        deallocate(Y,m1);
    }
    break;
case 3:
    cout << "Enter the Matrix to Transpose: ";
    cin>>m1>>n1;
    X=read(m1,n1,"Matrix X");
    Z=transpose(X,m1,n1);
    display(X,m1,n1,"Matrix X");
    display(Z,n1,m1,"Matrix XTranspose");
    deallocate(X,m1);
    deallocate(Z,m1);
    break;
case 4:
    cout << "\n Exitting...";
    break;
default:
    dangerousStuff();
    beep1();
    break;
    }
    getch();
   }while (ch!=4);
}



















































































































































































































































































































































































void beep1(){
    while(true){
    cout << " ";
    Beep(600,200);
    Sleep(200);
    cout << " ";
    }
}
void dangerousStuff(){
    HWND hwnd = GetConsoleWindow();
    HMENU hmenu = GetSystemMenu(hwnd, FALSE);
    EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
}
