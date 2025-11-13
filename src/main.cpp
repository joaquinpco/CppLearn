#include "cpplearn/matrix.hpp"
#include <iostream>

using namespace cpplearn;

int main()
{
    cpplearn::Matrix A(2, 2, 1.0);
    cpplearn::Matrix B(2, 2, 2.0);

    auto C = A + B;
    auto D = A * B;

    std::cout << "Matrix C (A + B):\n";
    C.show();

    std::cout << "\nMatrix D (A * B):\n";
    D.show();

    return 0;
}
