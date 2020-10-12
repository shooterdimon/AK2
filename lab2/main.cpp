#include <iostream>
#include <string.h>
#include "calculator.h"

using namespace std;

Calculator calc;
double a = 6.0;
double b = 8.0;



int main() {
    std::cout << "Multiplication result:\n";
    std::cout << "a * b = " << calc.Mul(a, b) << std::endl;
    return 0;
}
