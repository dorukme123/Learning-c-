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
		cout<<"1 - Добавить элемент в список"<<endl;
		cout<<"2 - Удалить элемент из списка"<<endl;
		cout<<"3 - Сортировка по алфавиту"<<endl;
		cout<<"4 - Сортировка по возрастанию значений"<<endl;
		cout<<"5 - Сортировка по убыванию значений"<<endl;
		cout<<"6 - Смещение вправо"<<endl;
		cout<<"7 - Смещение влево"<<endl;
		cout<<"8 - Вывод списка"<<endl;
		cout<<"0 - Выход"<<endl;
		int choose;
		cin>>choose;
		switch(choose)
		{
			case 1:
				{
					string name;
					int val;
					cout<<"Введите название: ";
					cin>>name;
					cout<<"Введите значение: ";
					cin>>val;
					list.insert(name,val);
					cout<<"Элемент добавлен в список"<<endl;
				}
				break;
			case 2:
				{
					list.del_next();
					cout<<"Последний элемент удален из списка"<<endl;
				}
				break;
			case 3:
				{
					list.sort_alphabet();
					cout<<"Сортировка элементов в алфавитном порядке произведена"<<endl;
				}
				break;
			case 4:
				{
					list.sort_ASC();
					cout<<"Сортировка элементов по возрастанию произведена"<<endl;
				}
				break;
			case 5:
				{
					list.sort_DESC();
					cout<<"Сортировка элементов по убыванию произведена"<<endl;
				}
				break;
			case 6:
				{
					list.right();
					cout<<"Смещение вправо произведено"<<endl;
				}
				break;
			case 7:
				{
					list.left();
					cout<<"Смещение влево произведено"<<endl;
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
				cout<<"Выбран неверный пункт меню"<<endl;
				break;
		}
		system("pause");
	}
	return 0;
}

