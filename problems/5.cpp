#include <iostream>
#include <cmath>

class Vector
{
private:
    int x,y,z;
public:
    Vector(){
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    Vector(int x,int y,int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void lenght(){
        // sqrt(i^2 + j^2 + k^2)
        std::cout << sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    }
    void addition(Vector a){
        int x1,y1,z1;
        x1 = x + a.x;
        y1 = y + a.y;
        z1 = z + a.z;
        printf("(%.d, %.d, %.d)", x1, y1, z1);
    }
    void substraction(Vector a){
        int x1,y1,z1;
        x1 = x - a.x;
        y1 = y - a.y;
        z1 = z - a.z;
        printf("(%.d, %.d, %.d)", x1, y1, z1);
    }
    void scalarMultip(Vector a){
        int x1,y1,z1;
        x1 = x * a.x;
        y1 = y * a.y;
        z1 = z * a.z;
        printf("(%.d, %.d, %.d)", x1, y1, z1);
    }
    void printValues(){
        printf("(%.d, %.d, %.d)", x, y, z);
    }
    // _cosineValue !! dont touch this method it barely works
    // there is a lot of bugs in this method i dont know how to fix them yet
    void cosineValue(Vector a){
        // a · b = ax · bx + ay · by + az · bz
        // |a| = sqrt(ax2 + ay2 + az2) 
        // |b| = sqrt(bx2 + by2 + bz2)
        // cosa = (a · b) / |a|*|b|
        float len1,len2,dot;
        float angle;
        dot = (x*a.x) + (y*a.y) + (z*a.z);
        len1 = (x*x) + (y*y) + (z*z);
        len2 = (a.x*a.x) + (a.y*a.y) + (a.z*a.z);
        angle = acos(dot/sqrt(len1*len2));
        printf("cos(θ) = %.3f",angle);
    }
    
};
int main(){
    Vector v1(3,4,2);
    Vector v2(4,2,1);
    // v1
    std::cout << "Lenght: ";
    v1.printValues();
    std::cout << " ";
    v1.lenght();
    std::cout << std::endl;
    // v2
    std::cout << "Lenght: ";
    v2.printValues();
    std::cout << " ";
    v2.lenght();
    std::cout << std::endl;
    // addition
    std::cout << "Addition v1 + v2: ";
    v1.addition(v2);
    std::cout << std::endl;
    // substraction
    std::cout << "Substraction v1 + v2: ";
    v1.substraction(v2);
    std::cout << std::endl;
    // Scalar Multiplication
    std::cout << "Scalar Multiplication v1 * v2: ";
    v1.scalarMultip(v2);
    std::cout << std::endl;
    // Cosine Value
    std::cout << "Cosine Value cos(θ): ";
    v1.cosineValue(v2);
    std::cout << std::endl;
    
    return 0;
}