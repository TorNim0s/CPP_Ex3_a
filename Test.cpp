#include <stdexcept>
#include "doctest.h"
#include "Notebook.hpp"

#define TEST_TEXT "Test"

using namespace ariel;
using namespace std;

Notebook notebook;

TEST_CASE("Good Input")
{
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix a{identity, 3, 3};  // constructor taking a vector and a matrix size

    

}