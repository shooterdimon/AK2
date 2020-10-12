#include "calculator.h"

// + function
int Calculator::Add (double a, double b)
{
	return a + b;
}
// - function
int Calculator::Sub (double a, double b)
{
    return Add (a, -b);
}
// * function 
int Calculator::Mul (double a, double b)
{
    return a * b;
}
// / function
int Calculator::Div (double a, double b)
{
    return a / b;
}