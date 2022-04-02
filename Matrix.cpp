#include "Matrix.hpp"

using namespace std;

namespace zich
{
    Matrix::Matrix(const vector<double> data, const int row, const int col) {}
    Matrix::Matrix(const int row, const int col) {}

    // Operator +
    Matrix Matrix::operator+(Matrix const &other) {return *this;}
    Matrix &Matrix::operator+=(Matrix const &other) {return *this;}
    Matrix &Matrix::operator++() {return *this;}
    Matrix Matrix::operator++(const int num) {return *this;}

    // Operator -
    Matrix Matrix::operator-(Matrix const &other) {return *this;}
    Matrix &Matrix::operator-=(Matrix const &other) {return *this;}
    Matrix &Matrix::operator--() {return *this;}
    Matrix Matrix::operator--(const int num) {return *this;}

    // Operator *
    Matrix Matrix::operator*(Matrix const &other) {return *this;}
    Matrix &Matrix::operator*=(Matrix const &other) {return *this;}
    Matrix Matrix::operator*(const double num) {return *this;}
    Matrix &Matrix::operator*=(const double num) {return *this;}

    // statements
    bool Matrix::operator<(Matrix &other) {return true;}
    bool Matrix::operator<=(Matrix &other) {return true;}
    bool Matrix::operator>(Matrix &other) {return true;}
    bool Matrix::operator>=(Matrix &other) {return true;}
    bool Matrix::operator==(Matrix &other) {return true;}
    bool Matrix::operator!=(Matrix &other) {return true;}

    // cout <<
    ostream &operator<<(ostream &os, const Matrix &mat) {return os;}

    // cout >>
    istream &operator>>(istream &os, Matrix &ourMat) {return os;}

    // * and -
    Matrix operator*(const double num, Matrix &ourMat) {return ourMat;}
    Matrix operator-(Matrix &ourMat) {return ourMat;}
}