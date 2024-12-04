#include <iostream>
#include <cmath> // For tan, cos, log, exp

// Function to compute tan(x)^sec(x)
double function(double x) {
    return std::pow(std::tan(x), 1 / std::cos(x)); // tan(x) raised to the power sec(x)
}

// First derivative of tan(x)^sec(x)
double first_derivative(double x) {
    // Calculating tan(x) and sec(x)
    double tanx = std::tan(x);
    double secx = 1 / std::cos(x); // Replacing sec(x) with 1/cos(x)

    // Derivative of tan(x)^sec(x) using logarithmic differentiation
    double term1 = secx * (std::pow(secx, 2) / tanx); // sec(x) * sec^2(x) / tan(x)
    double term2 = std::log(tanx) * secx * tanx; // log(tan(x)) * sec(x) * tan(x)

    // Return the result
    return std::pow(tanx, secx) * (term1 + term2);
}

// Second derivative of tan(x)^sec(x)
double second_derivative(double x) {
    // Calculating tan(x), sec(x), and log(tan(x))
    double tanx = std::tan(x);
    double secx = 1 / std::cos(x); // Replacing sec(x) with 1/cos(x)
    
    // Compute the first derivative
    double f_prime_x = first_derivative(x);

    // Calculate the first term needed for second derivative
    double term1 = secx * (std::pow(secx, 2) / tanx); // sec(x) * sec^2(x) / tan(x)
    double term2 = std::log(tanx) * secx * tanx; // log(tan(x)) * sec(x) * tan(x)

    // Second derivative using product and chain rule
    double result = f_prime_x * term1 + std::pow(tanx, secx) * (
        2 * secx * secx * (1 / tanx) - std::log(tanx) * secx * tanx
    );

    return result;
}

int main() {
    double x;
    int n;

    // Input x and derivative order
    std::cout << "Enter the value for x(in radians): ";
    std::cin >> x;
    std::cout << "Enter the order of derivative: ";
    std::cin >> n;

    // Check if x is in a valid domain (tan(x) and sec(x) are undefined at multiples of π/2)
    if (std::fmod(x, M_PI) == M_PI_2 || std::fmod(x, M_PI) == -M_PI_2) {
        std::cout << "Error: x must not be equal to π/2, 3π/2, etc. where tan(x) or sec(x) are undefined." << std::endl;
        return 1; // Exit with error code
    }

    // Compute and display result
    if (n == 1) {
        std::cout << "First derivative at x = " << x << ": " << first_derivative(x) << std::endl;
    } else if (n == 2) {
        std::cout << "Second derivative at x = " << x << ": " << second_derivative(x) << std::endl;
    } else {
        std::cout << "Error: Only first and second derivatives are supported." << std::endl;
    }

    return 0;
}
