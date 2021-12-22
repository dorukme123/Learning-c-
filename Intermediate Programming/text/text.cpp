#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#define isdelim(c) (std::isspace((c)) || std::ispunct((c)))
using namespace std;
char* each_word(char*& s)
{
    while(isdelim(*s))
        ++s; 
    char* p = s;
    while(*s && !isdelim(*s))
        ++s; 
    if(*s)
        *s++ = '\0';
    return (p != s) ? p : NULL;
}
int find(vector<string>s)
{
	string word;
	cout<<"������� ����� ��� ������"<<endl;
	cin>>word;
	for(int i=0;i<s.size();i++)
	{
		char* w;
		char x[1000];
		strcpy(x,s[i].c_str());
		char *p=(char *)x;
    	while((w = each_word(p)) != NULL)
        	if(strcmp(word.c_str(),w)==0)
        		return i;
	}
	return -1;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector <string> text;
	bool menu=true;
	do
	{
		system("cls");
		cout<<"�������� ����� ����"<<endl;
		cout<<"1 - �������� ����� ������"<<endl;
		cout<<"2 - ������� �����"<<endl;
		cout<<"3 - ����������� ������"<<endl;
		cout<<"4 - ������� ����� �� �����"<<endl;
		cout<<"5 - ����� � ������"<<endl;
		cout<<"0 - �����"<<endl;
		int choose;
		cin>>choose;
		switch(choose)
		{
			case 1:
				{
					string txt;
					cout<<"������� ����� ��� ����������"<<endl;
					cin.ignore();
					getline(cin,txt);
					text.push_back(txt);
					cout<<"����� ������ ������� ��������"<<endl;
				}
				break;
			case 2:
				{
					int number;
					cout<<"������� ����� ������, ������� ��������� �������"<<endl;
					cin>>number;
					number--;
					if(number>=0 && number<text.size())
					{
						text.erase(text.begin() + number);
						cout<<"����� ������ �� ������"<<endl;
					}
					else cout<<"�������� ����� ������"<<endl;
						
					
				}
				break;
			case 3:
				{
					int n1,n2;
					cout<<"������� ������ ������� ��� ������������"<<endl;
					cin>>n1>>n2;
					n1--;
					n2--;
					if(n1>=0 && n1<text.size() && n2>=0 && n2<text.size())
					{
						string tmp=text[n1];
						text[n1]=text[n2];
						text[n2]=tmp;
						cout<<"������ ������������"<<endl;
					}
					else cout<<"�������� ����� ������"<<endl;
					
				}
				break;
			case 4:
				{
					for(int i=0;i<text.size();i++)
						cout<<"\t"<<text[i]<<endl;					
				}
				break;
			case 5:
				{
					int n=find(text);
					if(n==-1)
						cout<<"����� �� �������!"<<endl;
					else 
					{
						cout<<"����� ������� � "<<n+1<<" ������"<<endl;
						cout<<"\t"<<text[n]<<endl;	
					}
					
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
	}while(menu);
	return 0;
} 
