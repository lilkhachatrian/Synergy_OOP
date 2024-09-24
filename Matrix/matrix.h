#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <stddef.h>
#include <iostream>
#include <algorithm>

class Matrix{
//constructors and destructor
public:
    Matrix();
    Matrix(size_t);
    Matrix(size_t, size_t);
    Matrix(size_t, size_t, double);
    Matrix(const Matrix&);
    Matrix(Matrix&&) noexcept;
    ~Matrix();

// copy and move assignment operators
    Matrix& operator=(const Matrix&);
    Matrix& operator=(Matrix&&) noexcept;

public:
// setters and getters 
    size_t get_rows() const;
    size_t get_columns() const;
    void set_size(size_t, size_t);
    bool is_empty();
    bool is_squared();
    void clear();
    void swap_rows(size_t, size_t);

private:
    void allocate(size_t, size_t);

public:
// scalar multiplication
    Matrix& operator*(double);

    friend Matrix operator+ (const Matrix&, const Matrix&);
    friend Matrix operator- (const Matrix&, const Matrix&);
    friend Matrix operator* (const Matrix&, const Matrix&);
    
    class doubleSubscript {
    private:
        double* m_matrix;

    public:
        doubleSubscript(double* matrix);
        double& operator[](size_t j) const ;
    };

    doubleSubscript operator[](size_t i) const;
    friend std::istream& operator>>(std::istream& in, Matrix& mat);
    friend std::ostream& operator<<(std::ostream& out, const Matrix& mat);

    double determinant();
    Matrix transpose() const;
    // Matrix inverse() const;

private:
    size_t m_row;
    size_t m_column;
    double** m_mat;

};

#endif