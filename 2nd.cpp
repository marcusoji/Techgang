#include <iostream>
#include <cmath> // for std::exp and std::pow

// Function to compute the nth order derivative of e^(ax - 2)
double nth_order_derivative(double a,  double x, int n) {
    // The nth derivative of e^(ax - 2) is (a^n) * e^(ax - 2)
    return std::pow(a, n) * std::exp(a * x - 2);
}

int main() {
    double a, x;
    int n;

    // Input values for a, x, and n
    std::cout << "Enter the value for a: ";
    std::cin >> a;
    
    std::cout << "Enter the value for x: ";
    std::cin >> x;
    std::cout << "Enter the order for derivative (n): ";
    std::cin >> n;

    // Ensure n is non-negative
    if (n < 0) {
        std::cout << "Error: The order of the derivative (n) must be non-negative." << std::endl;
        return 1; // Exit with an error code
    }

    // Compute the nth order derivative
    double result = nth_order_derivative(a,  x, n);

    // Output the result
    std::cout << "The " << n << "th order derivative of e^(" << a << "x - " << 2
              << ") at x = " << x << " is: " << result << std::endl;

    return 0;
}
