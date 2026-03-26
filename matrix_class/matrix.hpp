#pragma once
#include <cstddef>

class Matrix
{
    public:
        Matrix();
        Matrix(size_t r, size_t c, double initialValue = 0.0);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;
        ~Matrix();
    public:
        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;
    public:
        double& operator()(size_t i, size_t j);       // mutable
        double operator()(size_t i, size_t j) const; // const
    public:
        Matrix& operator+=(const Matrix& other);
        Matrix& operator-=(const Matrix& other);
        Matrix& operator*=(const Matrix& other);
        Matrix& operator*=(double scalar);
    public:
        Matrix transpose() const;
        //double determinant() const;
        //Matrix inverse() const;
        void print() const;
    public:
        size_t numRows() const;
        size_t numCols() const;
        bool isSquare() const;
        void fillRandom(double min, double max);
    private:
        size_t rows {};
        size_t cols {};
        double** data {};
};

Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, double scalar);
Matrix operator*(double scalar, const Matrix& rhs);
