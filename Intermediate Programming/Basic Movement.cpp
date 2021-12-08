#include <iostream>
using namespace std;
class matrix
{
	private:
		int n;
		int **a;
	public:
		matrix(char *s)
		{
			n=strlen(s);
			a=new int*[n];
			for(int i=0;i<n;i++)
				a[i]=new int[n];
			for(int i=0;i<n;i++)
				a[0][i]=s[i]-'0';
			for(int i=1;i<n;i++)
				a[i]=sdvig(a[i-1]);
		}
		int *sdvig(int *x)
		{
			int *res=new int[n];
			res[n-1]=x[0];
			for(int i=0;i<n-1;i++)
				res[i]=x[i+1];
			return res;
		}
		void print()
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					cout<<a[i][j];
				cout<<endl;
			}
		}
		~matrix()
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
    cout<<"enter a number: "<<endl;
	char s[500];
	cin>>s;
	matrix a(s);
	cout<<"output is: "<<endl;
	a.print();
	system("pause");
	return 0;
}
