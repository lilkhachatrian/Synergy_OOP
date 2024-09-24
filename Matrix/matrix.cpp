#include "matrix.h"
#include <stdexcept>


Matrix::Matrix() : m_row(0), m_column(0), m_mat(nullptr) {}
Matrix::Matrix(size_t size) : m_row(size), m_column(size) {
    allocate(m_row, m_column);
}

Matrix::Matrix(size_t row, size_t column) : m_row(row), m_column(column){
    allocate(m_row, m_column);
}

Matrix::Matrix(size_t row, size_t column, double num) : Matrix(row, column){
    allocate(m_row, m_column);
    for(size_t i = 0; i < m_row; ++i){
        for(size_t j = 0; j < m_column; ++j){
            m_mat[i][j] = num;
        }
    }
}

Matrix::Matrix(const Matrix& other){
    m_row = other.get_rows();
    m_column = other.get_columns();
    allocate(other.m_row, other.m_column);
    for(size_t i; i < m_row; ++i){
        for(size_t j; j < m_column; ++j){
            m_mat[i][j] = other.m_mat[i][j];
        }
    }
}

Matrix::Matrix(Matrix&& other) noexcept : m_row(other.m_row), m_column(other.m_column), m_mat(other.m_mat){
    other.m_row = 0;
    other.m_column = 0;
    other.m_mat = nullptr;
}

Matrix::~Matrix(){
    clear();
}

Matrix& Matrix::operator=(const Matrix& other){
    if(this != &other){
        clear();
        m_row = other.m_row;
        m_column = other.m_column;
        allocate(m_row, m_column);
        for(size_t i = 0; i < m_row; ++i){
            for(size_t j = 0; j < m_column; ++j){
                m_mat[i][j] = other.m_mat[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if(this != &other){
        clear();
        m_row = other.m_row;
        m_column = other.m_column;
        m_mat = other.m_mat;
        other.clear();
    }
    return *this;
}

size_t Matrix::get_rows() const {
    return m_row;
}

size_t Matrix::get_columns() const {
    return m_column;
}

void Matrix::set_size(size_t row, size_t column){
    if(m_row == 0 && m_column == 0){
        this->clear();
        m_row = row;
        m_column = column;
        this->allocate(row, column);
    }
    std::cout << "Matrix is not empty." << std::endl;
}

bool Matrix::is_empty(){
    if(m_row == 0 && m_column == 0) return true;
    return false;
}

bool Matrix::is_squared(){
    if(m_row == m_column) return true;
    return false;
}

void Matrix::clear(){
    for(size_t i = 0; i < m_row; ++i){
        delete[] m_mat[i];
    }
    delete[] m_mat;
    m_row = 0;
    m_column = 0;
    m_mat = nullptr;
}

void Matrix::allocate(size_t row, size_t column){
    m_mat = new double*[row];
    for(size_t i = 0; i < row; ++i){
        m_mat[i] = new double[column];
    }
}

void Matrix::swap_rows(size_t row1, size_t row2){
    for(size_t i = 0; i < m_column; ++i){
        double temp = m_mat[row1][i];
        m_mat[row1][i] = m_mat[row2][i];
        m_mat[row2][i] = temp;
    }
}

Matrix& Matrix::operator*(double scalar){
    for(size_t i = 0; i < m_row; ++i){
        for(size_t j = 0; j < m_column; ++j){
            m_mat[i][j] *= scalar;
        }
    }
    return *this;
}

Matrix operator+(const Matrix& m1, const Matrix& m2){
    size_t m1_row = m1.get_rows();
    size_t m1_col = m1.get_columns();
    size_t m2_row = m2.get_rows();
    size_t m2_col = m2.get_columns();
    if(m1_row != m2_row || m1_col != m2_col){
        throw std::invalid_argument("Matrices must have same dimentions for addition.");
    }
    Matrix result(m1_row, m1_col, 0);
    for(size_t i = 0; i < m1_row; ++i){
        for(size_t j = 0; j < m1_col; ++j){
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return result;
}

Matrix operator-(const Matrix& m1, const Matrix& m2){
    size_t m1_row = m1.get_rows();
    size_t m1_col = m1.get_columns();
    size_t m2_row = m2.get_rows();
    size_t m2_col = m2.get_columns();
    if(m1_row != m2_row || m1_col != m2_col){
        throw std::invalid_argument("Matrices must have same dimentions for subtraction.");
    }
    Matrix result(m1_row, m1_col, 0);
    for(size_t i = 0; i < m1_row; ++i){
        for(size_t j = 0; j < m1_col; ++j){
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return result;
}
Matrix operator*(const Matrix& m1, const Matrix& m2){
    if(m1.m_column != m2.m_row){
        std::invalid_argument("Dimentions do not match.");
    }
    Matrix result(m1.m_row, m2.m_column, 0);
        for(size_t i = 0; i < result.m_row;++i){
            for(size_t j = 0; j < result.m_column; ++j){
                for(size_t k = 0; k < result.m_row; ++k){
                    result[j][k] += m1[i][k] * m2[k][j];
                }
            }
        }
    return result;
}

Matrix::doubleSubscript::doubleSubscript(double* matrix) : m_matrix(matrix) {}
double& Matrix::doubleSubscript::operator[](size_t j) const {
    return m_matrix[j];
}

Matrix::doubleSubscript Matrix::operator[](size_t i) const {
    return doubleSubscript(m_mat[i]);
}

std::istream& operator>>(std::istream& in, Matrix& mat){
    for(size_t i = 0; i < mat.m_row; ++i){
        std::cout << "Enter numbers for " << i + 1 << " row: " << std::endl;
        for(size_t j = 0; j < mat.m_column; ++j){
            in >> mat[i][j];
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& mat){
    for(size_t i = 0; i < mat.m_row; ++i){
        for(size_t j = 0; j < mat.m_column; ++j){
            out << mat[i][j] << " ";
        }
        out << '\n';
    }
    return out;
}

double Matrix::determinant(){
    if(m_column != m_row){
        throw std::invalid_argument("Matrix had to be squared.");
    }
    
    Matrix mat = *this;
    double det = 1;
    for(size_t i = 0; i < m_row; ++i){
        double pivot = mat[i][i];
        if(pivot == 0){
            for(size_t j = i + 1; j < m_row; ++j){
                if(m_mat[j][i] != 0){
                    swap_rows(i, j);
                    pivot = m_mat[i][i];
                    det *= -1;
                }
            }
            if(pivot == 0) return 0;
        }
        
        for(size_t j = i+1; j < m_row; ++j){
            double multiplier = mat[j][i] / pivot;
            for(size_t k = i; k < m_row; ++k){
                mat[j][k] -= mat[i][k] * multiplier;
            }
        }
        det *= pivot;
    }
    return det;
}

Matrix Matrix::transpose() const {
    Matrix transposed(m_column, m_row, 0);
    for (size_t i = 0; i < m_row; ++i) {
        for (size_t j = 0; j < m_column; ++j) {
            transposed.m_mat[j][i] = m_mat[i][j];
        }
    }
    return transposed;
}

// Matrix Matrix::inverse() const;