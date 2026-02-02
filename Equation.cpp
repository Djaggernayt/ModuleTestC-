#include "quadratic_equation_solver.h"

std::vector<double> QuadraticEquationSolver::solve(double a, double b, double c) {
    if (a == 0) {
        throw std::invalid_argument("Coefficient 'a' cannot be zero in a quadratic equation.");
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return {}; // Нет действительных корней
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        return {root}; // Один корень
    } else {
        double sqrtDiscriminant = std::sqrt(discriminant);
        double root1 = (-b - sqrtDiscriminant) / (2 * a);
        double root2 = (-b + sqrtDiscriminant) / (2 * a);
        return {root1, root2}; // Два корня
    }
}