#include "matrix.cpp"
#include <iostream>

int main(){
    Matrix mat1(3);
    //double p = 8;
    for(size_t i = 0; i < 3; ++i){
        for(size_t j = 0; j < 3; ++j){
            mat1[i][j] = j;
        }
    }
    
   Matrix mat(mat1.transpose());
   std::cout << mat;

    std::cout << "Mat1 det = " << mat1.determinant() << std::endl;
    std::cout << "Mat det = " << mat.determinant() << std::endl;
}

