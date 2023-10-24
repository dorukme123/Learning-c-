#include <iostream>
#define N 50

class Polynomial
{
private:
    int coef[N]; // N = 1 -> x^1 , N = 2 -> x^2
    int degree;
public:
    Polynomial()
    {
        for(int i = 0; i < N; i++){
            coef[i] = 0;
        }
    }
    // setter
    inline void setAB(const int& x,const int& y){
        this->coef[y] = x;
        this->degree = setDegree();
    }
    // methods
    int setDegree(){
        // somewhat a getter
        int d = 0;
        for(int i = 0; i < N; i++){
            if(coef[i] != 0){
                d = i;
            }
        }
        return d;
    }
    void printValues(){
        // simply prints the polynomial
        for(int i = N-1; i >= 0; i--){
            if(coef[i] != 0){
                std::cout << coef[i] << "x^" << i << " ";
            }
        }
    }
    int evaluatePoly(int x){
        // poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]
        int p = 0;
        for(int i = degree; i >= 0; i--){
            p = coef[i] + (x*p);
        }
        return p;
    }
    Polynomial differentiate(){
        // differentiate pol
        if(degree == 0){
            Polynomial pol;
            pol.setAB(0,0);
            return pol;
        }
        // create new Polynomial
        Polynomial derivate; // (0, degree-1)
        derivate.degree = degree - 1;
        for(int i = 0; i < degree; i++){
            derivate.coef[i] = (i + 1)*coef[i + 1];
        }
        return derivate;
    }
    // copying by reference not value because array might be a lot bigger
    Polynomial substraction(const Polynomial& b) const {
        Polynomial a = *this;
        Polynomial c;
        for(int i = 0; i <= a.degree; i++){
            c.coef[i] += a.coef[i];
        }
        for(int j = 0; j <= b.degree; j++){
            c.coef[j] -= b.coef[j];
        }
        c.degree = c.setDegree();
        return c;
    }
    Polynomial addition(const Polynomial& b) const {
        Polynomial a = *this;
        Polynomial c;
        for(int i = 0; i <= a.degree; i++){
            c.coef[i] += a.coef[i];
        }
        for(int j = 0; j <= b.degree; j++){
            c.coef[j] += b.coef[j];
        }
        c.degree = c.setDegree();
        return c;
    }
    Polynomial multiplication(const Polynomial& b) const {
        Polynomial a = *this;
        Polynomial c;
        for(int i = 0; i <= a.degree; i++){
            for(int j = 0; j <= b.degree; j++){
                c.coef[i+j] += (a.coef[i]*b.coef[j]);
            }
        }
        c.degree = c.setDegree();
        return c;
    }
};

int main()
{
    Polynomial a;
    Polynomial b;
    Polynomial c;
    Polynomial d;
    Polynomial f;
    a.setAB(4,3); // 4x^3
    a.setAB(3,2); // 3x^2
    b.setAB(-6,5); // -6x^5
    b.setAB(-2,2); // -2x^2
    // a - b: (4x^3 + 3x^2) - (-6x^5 - (-2x^2))
    std::cout << "a - b = " << "\n";
    c = a.substraction(b);
    c.printValues();
    std::cout << std::endl;
    // a + b: (4x^3 + 3x^2) + (-6x^5 - (-2x^2))
    std::cout << "a + b = " << "\n";
    d = a.addition(b);
    d.printValues();
    std::cout << std::endl;
    // a * b: (4x^3 + 3x^2) * (-6x^5 - (-2x^2))
    std::cout << "a * b = " << "\n";
    f = a.multiplication(b);
    f.printValues();
    std::cout << std::endl;

    return 0;
}