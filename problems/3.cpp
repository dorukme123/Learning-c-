#include <iostream>
#include <cmath>
#include <vector>

class Trigonometry
{
private:
    float x;
public:
    Trigonometry(){
        this->x = 0;
    }
    Trigonometry(float x){
        this->x = x;
    }
    // getter and setter
    inline const float& getX() const { return this->x; }
    inline void setX(const float& x) { this->x = x; }
    // methods
    float calculateCos(){
        return cos(getX());
    }
    float calculateSin(){
        return sin(getX());
    }
    void printInstance(){
        printf("cos(%.f) = %.4f",getX(),calculateCos());
        std::cout << std::endl;
        printf("sin(%.f) = %.4f",getX(),calculateSin());
        std::cout << std::endl;
    }
  
};

int main(){
    
    Trigonometry trigonometry;
    std::cout << "\nenter numbs:\n";
    while(true){
        int a;
        std::cin >> a;
        std::cout << std::endl;
        trigonometry.setX(a);
        trigonometry.printInstance();
    }
    return 0;
}