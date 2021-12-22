#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Matrix::Matrix()
{
	n=0;
	a=NULL;
}
Matrix::Matrix(int n)
{
	this->n=n;
	a=new int*[n];
	for(int i=0;i<n;i++)
		a[i]=new int[n];
}
Matrix::Matrix(const Matrix& obj)
{
	this->n=obj.n;
	this->a=new int*[n];
	for(int i=0;i<n;i++)
	{
		this->a[i]=new int[n];
		for(int j=0;j<n;j++)
			this->a[i][j]=obj.a[i][j];
	}
}
Matrix::~Matrix()
{
	for(int i=0;i<n;i++)
		delete[]a[i];
	delete[]a;
}
void Matrix::input(int n)
{
	this->n=n;
	a=new int*[n];
	for(int i=0;i<n;i++)
		a[i]=new int[n];
	cout<<"Введите элементы матрицы"<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
}
void Matrix::load(string filename)
{
	ifstream in(filename.c_str());
	in>>n;
	a=new int*[n];
	for(int i=0;i<n;i++)
		a[i]=new int[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			in>>a[i][j];
	in.close();
}
void Matrix::save(string filename)
{
	ofstream out(filename.c_str());
	out<<n<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			out<<a[i][j]<<" ";
		out<<endl;
	}
	out.close();
}
void Matrix::print()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
}
Matrix& Matrix::operator =(Matrix m2)
{
	this->n=m2.n;
	this->a=new int*[n];
	for(int i=0;i<n;i++)
	{
		this->a[i]=new int[n];
		for(int j=0;j<n;j++)
			this->a[i][j]=m2.a[i][j];
	}
	return *this;
}
Matrix Matrix::operator +(Matrix m2)
{
	if(n!=m2.n)
		cout<<"Размерности матриц не совпадают"<<endl;
	else
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]+=m2.a[i][j];
	}
	return *this;
}
Matrix Matrix::operator -(Matrix m2)
{
	if(n!=m2.n)
		cout<<"Размерности матриц не совпадают"<<endl;
	else
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]-=m2.a[i][j];
	}
	return *this;
}
Matrix Matrix::operator *(Matrix m2)
{
	if(n!=m2.n)
		cout<<"Размерности матриц не совпадают"<<endl;
	else
	{
		Matrix res(n);
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				res.a[i][j] = 0;
				for (int k=0;k<n;k++)
					res.a[i][j] += a[i][k] * m2.a[k][j];
			}
		}
		*this=res;
	}
	return *this;
}
