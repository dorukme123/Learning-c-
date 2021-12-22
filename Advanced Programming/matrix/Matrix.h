#include <string>
using namespace std;
class Matrix
{
	private:
		int n;
		int **a;
	public:
		Matrix();
		Matrix(int n);
		Matrix(const Matrix &obj);
		~Matrix();
		void print();
		Matrix& operator =(Matrix m2);
		Matrix operator +(Matrix m2);
		Matrix operator -(Matrix m2);
		Matrix operator *(Matrix m2);
		void input(int n);
		void load(string filename);
		void save(string filename);
};

