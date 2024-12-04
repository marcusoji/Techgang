#include <iostream>
#include <cmath> // For std::pow and std::log
#include <iomanip> // For controlling precision

// Function to compute the value of a^(x^c)
double function(double a, double c, double x) {
    return std::pow(a, std::pow(x, c));
}

// Function to compute the first derivative of a^(x^c)
double first_derivative(double a, double c, double x) {
    double ln_a = std::log(a);
    double base_value = function(a, c, x); // Compute a^(x^c)
    return base_value * ln_a * c * x;
}

// Function to compute the second derivative of a^(x^c)
double second_derivative(double a, double c, double x) {
    double ln_a = std::log(a);
    double base_value = function(a, c, x); // Compute a^(x^c)
    double first_term = base_value * std::pow(ln_a, 2) * c * c * x * x;
    double second_term = base_value * ln_a * c;
    return first_term + second_term;
}

// Function to compute the nth derivative (currently stub for higher derivatives)
double nth_derivative(double a, double c, double x, int n) {
    if (n == 0) return function(a, c, x);
    if (n == 1) return first_derivative(a, c, x);
    if (n == 2) return second_derivative(a, c, x);

    // Placeholder for higher derivatives
    std::cerr << "Higher derivatives not implemented yet.\n";
    return NAN;
}

int main() {
    double a, c, x;
    int n;

    // Input values for a, c, x, and n
    std::cout << "Enter the value for a: ";
    std::cin >> a;
    std::cout << "Enter the value for c: ";
    std::cin >> c;
    std::cout << "Enter the value for x: ";
    std::cin >> x;
    std::cout << "Enter the order of the derivative (n): ";
    std::cin >> n;

    // Validate inputs
    if (n < 0) {
        std::cout << "Error: The order of the derivative (n) must be non-negative." << std::endl;
        return 1;
    }

    if (a <= 0) {
        std::cout << "Error: Base (a) must be positive." << std::endl;
        return 1;
    }

    // Compute the nth derivative
    double result = nth_derivative(a, c, x, n);

    // Output the result with high precision
    if (!std::isnan(result)) {
        std::cout << std::setprecision(15) << "The " << n << "th order derivative of " << a << "^(x^" << c
                  << ") at x = " << x << " is: " << result << std::endl;
    }

    return 0;
}
