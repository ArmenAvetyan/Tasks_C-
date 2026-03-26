#include "matrix.hpp"
#include <random>
#include <print>
#include <stdexcept>

Matrix::Matrix() {}

Matrix::Matrix(size_t r, size_t c, double initialValue) : rows{r}, cols{c}
{
    data = new double* [r];
    for(size_t i = 0; i < r; ++i)
    {
        data[i] = new double [c];
        for(size_t j = 0; j < c; ++j)
            data[i][j] = initialValue;
    }
}

Matrix::Matrix(const Matrix& other) : rows{other.rows}, cols{other.cols}
{
    data = new double* [rows];
    for(size_t i = 0; i < rows; ++i)
    {
        data[i] = new double [cols];
        for(size_t j = 0; j < cols; ++j)
            data[i][j] = other.data[i][j];
    }
}

Matrix::Matrix(Matrix&& other) noexcept : rows{other.rows}, cols{other.cols}, data{other.data}
{
    other.rows = 0;
    other.cols = 0;
    other.data = nullptr;
}

Matrix::~Matrix()
{
    for(size_t i = 0; i < rows; ++i)
        delete[] data[i];
    delete[] data;
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this == &other)
        return *this;

    for (size_t i = 0; i < rows; ++i)
        delete[] data[i];
    delete[] data;

    rows = other.rows;
    cols = other.cols;

    data = new double*[rows];
    for(size_t i = 0; i < rows; ++i)
    {
        data[i] = new double[cols];
        for(size_t j = 0; j < cols; ++j)
            data[i][j] = other.data[i][j];
    }

    return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept
{
    if (this == &other)
        return *this;

    for(size_t i = 0; i < rows; ++i)
        delete[] data[i];
    delete[] data;

    rows = other.rows;
    cols = other.cols;
    data = other.data;

    other.rows = 0;
    other.cols = 0;
    other.data = nullptr;

    return *this;
}

double& Matrix::operator()(size_t i, size_t j)
{
    if (i >= rows || j >= cols)
        throw std::out_of_range("Matrix indices out of range");
    return data[i][j];
}

double Matrix::operator()(size_t i, size_t j) const
{
    if (i >= rows || j >= cols)
        throw std::out_of_range("Matrix indices out of range");
    return data[i][j];
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
    if(lhs.numRows() != rhs.numRows() || lhs.numCols() != rhs.numCols())
        throw std::invalid_argument("Matrix sizes must match for addition");

    Matrix res = lhs;
    res += rhs;
    return res;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
    if (rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Matrix sizes must match for addition");

    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < cols; ++j)
            data[i][j] += other.data[i][j];
    }
    return *this;
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs)
{
    if(lhs.numRows() != rhs.numRows() || lhs.numCols() != rhs.numCols())
        throw std::invalid_argument("Matrix sizes must match for subtraction");

    Matrix res = lhs;
    res -= rhs;
    return res;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
    if(rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Matrix sizes must match for subtraction");

    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < cols; ++j)
            data[i][j] -= other.data[i][j];
    }
    return *this;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
    if(lhs.numCols() != rhs.numRows())
        throw std::invalid_argument("Matrix sizes must match for multiplication");

    Matrix res = lhs;
    res *= rhs;
    return res;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
    if(cols != other.rows)
        throw std::invalid_argument("Matrix sizes must match for multiplication");

    Matrix res {rows, other.cols};

    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < other.cols; ++j)
        {
            for(size_t k = 0; k < cols; ++k)
                res.data[i][j] += data[i][k] * other.data[k][j];
        }
    }
    *this = std::move(res);
    return *this;
}

Matrix operator*(const Matrix& lhs, double scalar)
{
    Matrix res = lhs;
    res *= scalar;
    return res;
}

Matrix operator*(double scalar, const Matrix& rhs)
{
    Matrix res = rhs;
    res *= scalar;
    return res;
}

Matrix& Matrix::operator*=(double scalar)
{
    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < cols; ++j)
            data[i][j] *= scalar;
    }
    return *this;
}

Matrix Matrix::transpose() const
{
    Matrix res {cols, rows};

    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < cols; ++j)
            res(j, i) = data[i][j];
    }

    return res;
}

void Matrix::print() const
{
    std::println();

    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < cols; ++j)
            std::print("{:.2f} ", data[i][j]);
        std::println();
    }
    std::println();
}

size_t Matrix::numRows() const
{
    return rows;
}

size_t Matrix::numCols() const
{
    return cols;
}

bool Matrix::isSquare() const
{
    return rows == cols;
}

void Matrix::fillRandom(double min, double max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(min, max);

    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < cols; ++j)
            data[i][j] = dist(gen);
    }
}
