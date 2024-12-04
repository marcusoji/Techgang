#include <iostream>
#include <cmath> // For std::exp and std::log

// Function to compute the value of x^x
double function(double x) {
    return std::exp(x * std::log(x));
}

// First derivative of x^x
double first_derivative(double x) {
    return function(x) * (std::log(x) + 1);
}

// Second derivative of x^x
double second_derivative(double x) {
    return function(x) * (std::pow(std::log(x) + 1, 2) + 1 / x);
}

int main() {
    double x;
    int n;

    // Input values for x and the order of the derivative
    std::cout << "Enter the value for x: ";
    std::cin >> x;
    std::cout << "Enter the order of the derivative (n): ";
    std::cin >> n;

    // Validate input
    if (x <= 0) {
        std::cout << "Error: x must be greater than 0 for x^x." << std::endl;
        return 1; // Exit with error code
    }

    if (n < 0 || n > 2) {
        std::cout << "Error: This program supports only the first and second derivatives (n = 1 or 2)." << std::endl;
        return 1; // Exit with error code
    }

    // Compute and display the derivatives
    if (n == 0) {
        std::cout << "Function value: " << function(x) << std::endl;
    } else if (n == 1) {
        std::cout << "First derivative: " << first_derivative(x) << std::endl;
    } else if (n == 2) {
        std::cout << "Second derivative: " << second_derivative(x) << std::endl;
    }

    return 0;
}
