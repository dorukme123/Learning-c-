#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

class Rectangle
{
private:
    // bl = Bottom-left , tr = Top-right
    double blX,blY,trX,trY;
    double dx,dy;
public:
    Rectangle(){
        this->blX = 0;
        this->blY = 0;
        this->trX = 0;
        this->trY = 0;
        this->dx = 0;
        this->dy = 0;
    }
    Rectangle(double blX,double blY,double trX,double trY,double dx,double dy){
        this->blX = blX;
        this->blY = blY;
        this->trX = trX;
        this->trY = trY;
        this->dx = dx;
        this->dy = dy;
    }
    // getters
    inline const double& getblX() const { return this->blX; }
    inline const double& getblY() const { return this->blY; }
    inline const double& gettrX() const { return this->trX; }
    inline const double& gettrY() const { return this->trY; }
    inline const double& getdX() const { return this->dx; }
    inline const double& getdY() const { return this->dy; }
    // setters
    inline void setblX(const double& blX) { this->blX = blX; }
    inline void setblY(const double& blY) { this->blY = blY; }
    inline void settrX(const double& trX) { this->trX = trX; }
    inline void settrY(const double& trY) { this->trY = trY; }
    inline void setdX(const double& dx) { this->dx = dx; }
    inline void setdY(const double& dy) { this->dy = dy; }
    // methods
    void setBlandTr(double blX,double blY,double trX,double trY){
        setblX(blX);
        setblY(blY);
        settrX(trX);
        settrY(trY);
    }
    void setPoint(double dx,double dy){
        setdX(dx);
        setdY(dy);
    }
    bool checkIfPointInside(){
        if (getdX() > getblX() and getdX() < gettrX() and getdY() > getblY() and getdY() < gettrY())
            return true;
        else{
            return false;
        }
    }
    void printValues(){
        // finding Top-left and Bottom-right
        double tlX,tlY,brX,brY;
        tlX = getblX();
        tlY = gettrY();
        brX = gettrX();
        brY = getblY();
        printf("Top-left( %.1f, %.1f )",tlX,tlY);
        std::cout << "\n";
        printf("Bottom-left( %.1f, %.1f )",getblX(),getblY());
        std::cout << "\n";
        printf("Top-right( %.1f, %.1f )",gettrX(),gettrY());
        std::cout << "\n";
        printf("Bottom-right( %.1f, %.1f )",brX,brY);
        std::cout << "\n";
        printf("Point( %.1f, %.1f )",getdX(),getdY());
        std::cout << "\n";
    }
    
};

class Triangle
{
private:
    double x,y,x1,y1,x2,y2;
    double dx,dy;
public:
    Triangle(){
        this->x = 0;
        this->y = 0;
        this->x1 = 0;
        this->y1 = 0;
        this->x2 = 0;
        this->y2 = 0;
        this->dx = 0;
        this->dy = 0;
    }
    Triangle(double x,double y,double x1,double y1,double x2,double y2,double dx, double dy){
        this->x = x;
        this->y = y;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->dx = dx;
        this->dy = dy;
    }
    // getters
    inline const double& getX() const { return this->x; }
    inline const double& getY() const { return this->y; }
    inline const double& getX1() const { return this->x1; }
    inline const double& getY1() const { return this->y1; }
    inline const double& getX2() const { return this->x2; }
    inline const double& getY2() const { return this->y2; }
    inline const double& getDx() const { return this->dx; }
    inline const double& getDy() const { return this->dy; }
    // setters
    inline void setX(const double& x) { this->x = x; }
    inline void setY(const double& y) { this->y = y; }
    inline void setX1(const double& x1) { this->x1 = x1; }
    inline void setY1(const double& y1) { this->y1 = y1; }
    inline void setX2(const double& x2) { this->x2 = x2; }
    inline void setY2(const double& y2) { this->y2 = y2; }
    inline void setDx(const double& dx) { this->dx = dx; }
    inline void setDy(const double& dy) { this->dy = dy; }
    // methods:
    void setTriangle(double x,double y,double x1,double y1,double x2,double y2){
        setX(x);
        setX1(x1);
        setX2(x2);
        setY(y);
        setY2(y2);
        setY2(y2);
    }
    void setPoint(double dx,double dy){
        setDx(dx);
        setDy(dy);
    }
    //   Math behind it:
    //   Area(Δ) = (1/2)|x*(y1-y2)+x1*(y2-y)+x2*(y-y1)|
    float checkArea(double x,double y,double x1,double y1,double x2,double y2){
        return abs((x*(y1-y2) + x1*(y2-y) + x2*(y-y1))/2.0);
    }
    bool checkIfPointInside(){
        // This method is called finding area of a triangle by determinant:
        // ----------------------------------------------------------------
        // P(dx,dy)
        // Area(ΔABC):
        float Area = checkArea(getX(), getY(), getX1(), getY1(), getX2(), getY2());
        // Area(ΔPBC): 
        float Area1 = checkArea(getDx(), getDy(), getX1(), getY1(), getX2(), getY2());
        // Area(ΔPAC): 
        float Area2 = checkArea(getX(), getY(), getDx(), getDy(), getX2(), getY2());
        // Area(ΔPAB):  
        float Area3 = checkArea(getX(), getY(), getX1(), getY1(), getDx(), getDy());
        // if Area = Area1 + Area2 + Area3 => true
        return (Area == Area1 + Area2 + Area3);
    }
    void printValues(){
        printf("A( %.1f, %.1f )",getX(),getY());
        std::cout << "\n";
        printf("B( %.1f, %.1f )",getX1(),getY1());
        std::cout << "\n";
        printf("C( %.1f, %.1f )",getX2(),getY2());
        std::cout << "\n";
        printf("P( %.1f, %.1f )",getDx(),getDy());
        std::cout << "\n";
    }    
};

class Circle
{
private:
    int radius;
    double x,y,dx,dy;
public:
    Circle(){
        this->x = 0;
        this->y = 0;
        this->dx = 0;
        this->dy = 0;
        this->radius = 0;
    }
    Circle(int radius,double x,double y,double dx, double dy){
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
        this->radius = radius;
    }
    // getters
    inline const int& getRadius() const { return this->radius; }
    inline const double& getX() const { return this->x; }
    inline const double& getY() const { return this->y; }
    inline const double& getDx() const { return this->dx; }
    inline const double& getDy() const { return this->dy; }
    // setters
    inline void setRadius(const int& radius) { this->radius = radius; }
    inline void setX(const double& x) { this->x = x; }
    inline void setY(const double& y) { this->y = y; }
    inline void setDx(const double& dx) { this->dx = dx; }
    inline void setDy(const double& dy) { this->dy = dy; }
    // methods:
    void setCenter(int x,int y){
        setX(x);
        setY(y);
    }
    void setPoint(int dx, int dy){
        setDx(dx);
        setDy(dy);
    }
    void setR(int radius){
        setRadius(radius);
    }
    bool checkIfPointInside(){
        // (dx - x)^2 + (dy - y)^2 < radius^2
        if(pow((getDx() - getX()),2) + pow((getDy() - getY()),2) < pow(getRadius(),2)){
            return true;
        }
        else{
            return false;
        }
    }
    void printValues(){
        printf("center( %.1f, %.1f )",getX(),getY());
        std::cout << "\n";
        printf("point( %.1f, %.1f )",getDx(),getDy());
        std::cout << "\n";
        std::cout << "Radius: " << getRadius() << "\n";
    }
    
};

int main()
{
    // Circle setup:
    std::cout << "Circle: " << std::endl;
    Circle circle;
    circle.setCenter(0,0);
    circle.setRadius(2);
    circle.setPoint(2,2);
    circle.printValues();
    std::cout << std::boolalpha << circle.checkIfPointInside() << "\n";
    
    std::cout << std::endl;
    
    // Triangle setup:
    std::cout << "Triangle: " << std::endl;
    Triangle triangle;
    triangle.setTriangle(0,0,1,2,2,0);
    triangle.setPoint(1.0,0.5);
    triangle.printValues();
    std::cout << std::boolalpha << triangle.checkIfPointInside();
    
    std::cout << std::endl;
    
    // Rectangle setup:
    std::cout << "Rectangle: " << std::endl;
    Rectangle rectangle;
    rectangle.setBlandTr(0,0,4,4);
    rectangle.setPoint(2,2);
    rectangle.printValues();
    std::cout << std::boolalpha << rectangle.checkIfPointInside();
    
    return 0;
}
