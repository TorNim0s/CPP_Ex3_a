#include <iostream>
#include <vector>

namespace zich
{
    class Matrix
    {
    private:
        std::vector<double> mat;
        int row;
        int col;

    public:
        // Constructors
        Matrix(const std::vector<double> data, const int row, const int col);
        Matrix(const int row, const int col);

        // Operator +
        Matrix operator+(Matrix const &other);
        Matrix &operator+=(Matrix const &other);
        Matrix &operator++();
        Matrix operator++(const int num);

        // Operator -
        Matrix operator-(Matrix const &other);
        Matrix &operator-=(Matrix const &other);
        Matrix &operator--();
        Matrix operator--(const int num);

        // Operator *
        Matrix operator*(Matrix const &other);
        Matrix &operator*=(Matrix const &other);
        Matrix operator*(const double num);
        Matrix &operator*=(const double num);

        // statements
        bool operator<(Matrix &other);
        bool operator<=(Matrix &other);
        bool operator>(Matrix &other);
        bool operator>=(Matrix &other);
        bool operator==(Matrix &other);
        bool operator!=(Matrix &other);

        // cout <<
        friend std::ostream & operator<<(std::ostream &os, const Matrix &ourMat);

        // cout >>
        friend std::istream &operator>>(std::istream &os, Matrix &ourMat);

        // * and -
        friend Matrix operator*(const double num, Matrix &ourMat);
        friend Matrix operator-(Matrix &ourMat);
    };
}