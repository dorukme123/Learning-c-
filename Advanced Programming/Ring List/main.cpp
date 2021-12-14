#include "circle_list.h"
#include <string>
#include <iostream>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool menu=true;
	circle_list list;
	while(menu)
	{
		system("cls");
		cout<<"1 - �������� ������� � ������"<<endl;
		cout<<"2 - ������� ������� �� ������"<<endl;
		cout<<"3 - ���������� �� ��������"<<endl;
		cout<<"4 - ���������� �� ����������� ��������"<<endl;
		cout<<"5 - ���������� �� �������� ��������"<<endl;
		cout<<"6 - �������� ������"<<endl;
		cout<<"7 - �������� �����"<<endl;
		cout<<"8 - ����� ������"<<endl;
		cout<<"0 - �����"<<endl;
		int choose;
		cin>>choose;
		switch(choose)
		{
			case 1:
				{
					string name;
					int val;
					cout<<"������� ��������: ";
					cin>>name;
					cout<<"������� ��������: ";
					cin>>val;
					list.insert(name,val);
					cout<<"������� �������� � ������"<<endl;
				}
				break;
			case 2:
				{
					list.del_next();
					cout<<"��������� ������� ������ �� ������"<<endl;
				}
				break;
			case 3:
				{
					list.sort_alphabet();
					cout<<"���������� ��������� � ���������� ������� �����������"<<endl;
				}
				break;
			case 4:
				{
					list.sort_ASC();
					cout<<"���������� ��������� �� ����������� �����������"<<endl;
				}
				break;
			case 5:
				{
					list.sort_DESC();
					cout<<"���������� ��������� �� �������� �����������"<<endl;
				}
				break;
			case 6:
				{
					list.right();
					cout<<"�������� ������ �����������"<<endl;
				}
				break;
			case 7:
				{
					list.left();
					cout<<"�������� ����� �����������"<<endl;
				}
				break;
			case 8:
				{
				    list.show();
				}
				break;
			case 0:
				menu=false;
				break;
			default:
				cout<<"������ �������� ����� ����"<<endl;
				break;
		}
		system("pause");
	}
	return 0;
}

