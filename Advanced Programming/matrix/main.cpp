#include "Matrix.h"
#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	Matrix m1,m2;
	bool menu=true;
	do
	{
		system("cls");
		cout<<"�������� ����� ����"<<endl;
		cout<<"1 - ������ ����� ������� � ����������"<<endl;
		cout<<"2 - ������ ����� ������� �� �����"<<endl;
		cout<<"3 - �������� ������"<<endl;
		cout<<"4 - ��������� ������"<<endl;
		cout<<"5 - ��������� ������"<<endl;
		cout<<"6 - ����� ������ �� �����"<<endl;
		cout<<"7 - ����� ������ � ����"<<endl;
		cout<<"0 - �����"<<endl;
		int choose;
		cin>>choose;
		switch(choose)
		{
			case 1:
				{
					cout<<"������� ����������� ������"<<endl;
					cin>>n;
					m1.input(n);
					m2.input(n);
				}
				break;
			case 2:
				{
					m1.load("matrix1.txt");
					m2.load("matrix2.txt");
					cout<<"������� ������� �� �����"<<endl;	
				}
				break;
			case 3:
				{
					m1=m1+m2;
					m1.print();
				}
				break;
			case 4:
				{
					m1=m1-m2;
					m1.print();
				}
				break;
			case 5:
				{
					m1=m1*m2;
					m1.print();
				}
				break;
			case 6:
				{
					m1.print();
					cout<<endl<<endl;
					m2.print();
				}
				break;
			case 7:
				{
					m1.save("matrix1.txt");
					m2.save("matrix2.txt");
					cout<<"������� �������� � ����"<<endl;	
				}
				break;
			case 0:
				menu=false;
				break;
			default:
				cout<<"������ �������� ����� ����"<<endl;
		}
		system("pause");
	}while(menu);	
	return 0;
}
