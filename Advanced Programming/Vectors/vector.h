#ifndef LAB002_VECTOR
#define LAB002_VECTOR

class Vector
{
public:
	Vector();
	Vector(Point2d f, Point2d s);
	Vector(const Vector& vct);
	~Vector();
	int info();
	static int size;

	friend Point2d operator+(const Vector& v1, const Vector& v2);
	friend Point2d operator-(const Vector& v1, const Vector& v2);


	friend double operator*(const Vector& v1, const Vector& v2);
	friend Vector operator-(Vector& v1);

	int get_length();

	Point2d get_coords();



private:
	int id;
	int length;
	Point2d coords_f;
	Point2d coords_s;
	Point2d coords;
};


#endif LAB002_VECTOR
