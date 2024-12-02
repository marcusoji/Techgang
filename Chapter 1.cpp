#include <iostream>
#include <cmath> // for std::exp and std::pow

// Function to compute the nth order derivative of e^(bx² + cx - 2)
double nth_order_derivative(double b, double c, double x, int n) {
    if (n == 0) {
        // Base case: 0th derivative is the main function itself
        return std::exp(b * x * x + c * x - 2);
    } else if (n == 1) {
        // First derivative
        return (2 * b * x + c) * std::exp(b * x * x + c * x - 2);
    } else if (n == 2) {
        // Second derivative
        double multiplier = (2 * b * x + c);
        return (multiplier * multiplier + 2 * b) * std::exp(b * x * x + c * x - 2);
    } else if (n == 3) {
        // Third derivative
        double multiplier = (2* b * x + c);
        return (multiplier * multiplier * multiplier + 6 * b * multiplier + 4 * b * c) * std::exp(b * x * x + c * x - 2);
    } else {
        // General case: Use recurrence relation
        double multiplier = 2 * b * x + c;
        return multiplier * nth_order_derivative(b, c, x, n - 1) +
               2 * b * (n - 1) * nth_order_derivative(b, c, x, n - 2);
    }
}

int main() {
    double b, c, x;
    int n;

    // Input values
    std::cout << "Enter  b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >>c;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter the order of the derivative (n): ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "The order of the derivative must be non-negative." << std::endl;
        return 1;
    }

    // Compute nth order derivative
    double result = nth_order_derivative(a, c, x, n);

    // Output the result
    std::cout << "The " << n << "th order of the derivative of e^(" << b<< "x² + " << c << "x - 2) at x = " << x << " is: " << result << std::endl;

    return 0;
}
