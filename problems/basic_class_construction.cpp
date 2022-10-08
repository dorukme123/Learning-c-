#include <stdio.h>
#include <iostream>
#include <algorithm>
// 1-
class Foo
{
    private:
        int variable1;
        int variable2;
    public:
        Foo(int variable1,int variable2)
        {
            this->variable1 = variable1;
            this->variable2 = variable2;
        }
        ~Foo(){}
        // getters
        inline const int& getvar1() const { return this->variable1; }
        inline const int& getvar2() const { return this->variable2; }
        // setters
        inline void setvar1(const int& variable1) { this->variable1 = variable1; }
        inline void setvar2(const int& variable2) { this->variable2 = variable2; }
        // methods
        void display(){
            std::cout << getvar1() << "\n";
            std::cout << getvar2() << "\n";
        }
        void change(int variable1,int variable2){
            setvar1(variable1);
            setvar2(variable2);
        }
        int getsums(){
            return getvar1() + getvar2(); 
        }
        int findLargest(){
            return std::max(getvar1(),getvar2());
        }
};

int main()
{
    int var1,var2;
    std::cin >> var1 >> var2;
    Foo foo(var1,var2);
    foo.display();
    return 0;
}
