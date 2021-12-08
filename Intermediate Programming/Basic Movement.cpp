#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
class game
{
	private:
		int n;
		int **a;
		int posX,posY;
	public:
		game(int n)
		{
			n++;
			this->n=n;
			a=new int*[n];
			for(int i=0;i<n;i++)
				a[i]=new int[n];
			for(int i=0;i<n;i++)
			{
				a[i][0]=1;
				a[0][i]=1;
				a[i][n-1]=1;
				a[n-1][i]=1;
			}

			for(int i=1;i<n-1;i++)
				for(int j=1;j<n-1;j++)
					a[i][j]=rand()%2;
		}
		bool start(int x,int y)
		{
			if(a[x][y]==0)
			{
				posX=x;
				posY=y;
				return true;
			}
			else return false;

		}
		bool simulation(char x)
		{
			int newX=posX;
			int newY=posY;
			switch(x)
			{
				case 'w':
					newY--;
					break;
				case 's':
					newY++;
					break;
				case 'd':
					newX++;
					break;
				case 'a':
					newX--;
					break;
				case 'q':
					cout<<"("<<posX<<","<<posY<<") ";
					cout<<"quit!"<<endl;
					return false;
					break;
				case 'x':
					print();
					break;
			}
			if(a[newY][newX]==0)
			{
				posX=newX;
				posY=newY;
				cout<<"("<<posX<<","<<posY<<") "<<endl;
			}
			else
			{
				cout<<"("<<posX<<","<<posY<<") ";
				cout<<"start!"<<endl;

			}
			return true;
		}
		void print()
		{
			for(int i=1;i<n-1;i++)
			{
				for(int j=1;j<n-1;j++)
				if(j==posX && i==posY)
					cout<<"*";
				else
					cout<<a[i][j];
				cout<<endl;
			}
		}
		~game()
		{
			for(int i=0;i<n;i++)
				delete[]a[i];
			delete[]a;
		}

};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n,x,y;
	srand(time(0));
	cout<<"Lenght of the space: "<<endl;
	cin>>n;
	game a(n);
	cout<<"Created space"<<endl;
	a.print();
	do
	{
		cout<<"give the coordinates to begin : "<<endl;
		cout<<"X=";
		cin>>x;
		cout<<"Y=";
		cin>>y;

	}while(!a.start(x,y));
	cout<<"command list"<<endl;
	cout<<"w-up"<<endl;
	cout<<"s-down"<<endl;
	cout<<"a-left"<<endl;
	cout<<"d-right"<<endl;
	cout<<"x-show moving space"<<endl;
	cout<<"q-quit"<<endl;
	bool move=true;
	while(move)
	{

		cout<<"enter the command"<<endl;
		char x;
		cin>>x;
		move=a.simulation(x);

	}
	return 0;
}

