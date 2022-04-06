#include <stdexcept>
#include "doctest.h"
#include "Matrix.hpp"

using namespace zich;
using namespace std;

TEST_CASE("Good Cases")
{

    vector<double> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> v2 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<double> v3 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<double> v4 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<double> v5 = {10, 10, 10, 10, 10, 10, 10, 10, 10};

    Matrix m1(v1, 3, 3);
    Matrix m2(v2, 3, 3);
    Matrix m3(v3, 3, 3);
    Matrix m4(v4, 10, 3);
    Matrix m5(v4, 3, 10);
    Matrix m6(v5, 3, 3);

    CHECK(m1 > m2);
    CHECK(m1 >= m2);
    CHECK(m2 < m3);
    CHECK(m2 <= m3);
    CHECK(m2 == m2);
    CHECK(m3 != m2);

    CHECK(++m2 == m3);
    CHECK_NOTHROW(m2--);
    CHECK(--m3== m2);
    CHECK_NOTHROW(m3++);
    CHECK(m2 * 0 == m3);
    CHECK(m1 * 0 + m2 == m3 * 0);
    CHECK((m2 += m3) == m3); // we change m2 in here
    CHECK(m2 == m3);
    CHECK((m2 -= m3) != m3); // we change m2 in here again back
    CHECK_NOTHROW(m2 *= m3);
    CHECK((m2 * m3) == m2);

    CHECK_NOTHROW(m3--);
    CHECK(m3 == m2);
    CHECK_NOTHROW(m3++);
    CHECK_NOTHROW(--m3);
    CHECK(m3 == m2);
    CHECK_NOTHROW(++m3);

    // big tests
    CHECK((m5 * m4) == m6);
}

TEST_CASE("Bad Cases")
{
    vector<double> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Matrix m1(v1, 3, 4);
    Matrix m2(v1, 4, 3);

    bool res;

    // Operation on different sizes of matrix
    CHECK_THROWS(m1 + m2);
    CHECK_THROWS(m1 += m2);
    CHECK_THROWS(m1 - m2);
    CHECK_THROWS(m1 -= m2);
    CHECK_THROWS(m2 * m1); // m1 * m2 is ok it will get us a matrix 3x3
    CHECK_THROWS(m2 *= m1);

    // Invalid comprasion
    CHECK_THROWS(res = (m1 == m2));
    CHECK_THROWS(res = (m1 != m2));
    CHECK_THROWS(res = (m1 > m2));
    CHECK_THROWS(res = (m1 >= m2));
    CHECK_THROWS(res = (m1 < m2));
    CHECK_THROWS(res = (m1 <= m2));

    // Invalid Intialization
    CHECK_THROWS(Matrix(v1, -1, 4));
    CHECK_THROWS(Matrix(v1, 4, -1));
    CHECK_THROWS(Matrix(v1, 0, 0));
    CHECK_THROWS(Matrix(v1, 0, 4));
    CHECK_THROWS(Matrix(v1, 4, 0));
    CHECK_THROWS(Matrix(v1, -4, -4));
    CHECK_THROWS(Matrix(v1, 200, 200));
}