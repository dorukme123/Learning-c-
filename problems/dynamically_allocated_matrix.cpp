#include <iostream>

template <typename T>
class Matrix
{
private:
    T** M;
    int rows,cols; // rows and cols
public:
    Matrix()
    {
        this->rows = 0;
        this->cols = 0;
        this->M = nullptr;
    }
    Matrix(int rows,int cols){
        this->rows = rows;
        this->cols = cols;
        this->M = (T**) new T*[rows]; // number of pointers
        
        // memoryalloc() !NEEDS TO BE ON TOP BECAUSE IF IT DOESNT ALLOCATE MEMORY BEFORE-END IT HAVE ANY PLACE TO PUT VALUES
        for(int k = 0; k < rows; k++){
            M[k] = (T*) new T[cols];
        }
        // fill matrix
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                M[i][j] = 0;
            }
        }
        
    }
    void displayMatrix(){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                std::cout << M[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    void fillMatrix(){
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                int a;
                std::cin >> a;
                M[i][j] = a;
            }
        }
    }
    Matrix operator+(const Matrix& B){ // its done dont touch
        Matrix temp(rows,cols);  
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    temp.M[i][j]+=M[i][j]+B.M[i][j];
                }
            }
        return temp;
    }
    Matrix operator-(const Matrix& B){ // also this one it works
        Matrix temp(rows,cols); 
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                temp.M[i][j]=M[i][j]-B.M[i][j];
            }
        }
        return temp;
    }
    Matrix operator*(const Matrix& B){ // it works dont touch!
        Matrix temp(cols,rows);  
        for(int i=0;i<rows;i++){
            for(int j=0;j<B.cols;j++){
                for(int k =0;k<cols;k++){
                    temp.M[i][j]+=M[i][k]*B.M[k][j];
                }
            }
        }
        return temp;          
    }
    ~Matrix(){
        // delete memoryalloc
        if(cols > 0){
            for(int i = 0; i < rows; i++){
                delete[] M[i];
            }
        }
        if(rows > 0){
            delete[] M;
        }
    }
    friend std::ostream &operator<<(std::ostream &os, const Matrix &m) { // somehow works dont touch
        for (int i=0; i < m.rows; ++i) {
            for (int j=0; j < m.cols; ++j) {
                os << m.M[i][j] << " " ;
            }
            os << '\n';
        }
        return os;
    }
};


int main(){
    // dont forget the template of matrix
    Matrix<int> a(2,2);
    Matrix<int> b(2,2);
    a.fillMatrix();
    std::cout << "\n" << "Matris A:" << std::endl;
    a.displayMatrix();
    std::cout << std::endl;
    b.fillMatrix();
    std::cout << "\n" << "Matris A:" << std::endl;
    b.displayMatrix();
    std::cout << std::endl;
    std::cout << "A + B = " << std::endl;
    std::cout << (a+b);
    std::cout << std::endl;
    std::cout << "A - B = " << std::endl;
    std::cout << (a-b);
    std::cout << std::endl;
    std::cout << "A * B = " << std::endl;
    std::cout << (a*b);
    std::cout << std::endl;
    return 0;
}
