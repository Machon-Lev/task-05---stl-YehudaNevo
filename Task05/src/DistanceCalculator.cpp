#include "DistanceCalculator.h"
#include <cmath>
#include <algorithm>

double EuclideanCalculator::calculate(const City& city1, const City& city2) const {
    double dx = city2.x - city1.x;
    double dy = city2.y - city1.y;
    return std::sqrt(dx * dx + dy * dy);
}

double ChebyshevCalculator::calculate(const City& city1, const City& city2) const {
    return std::max(std::abs(city2.x - city1.x), std::abs(city2.y - city1.y));
}

double ManhattanCalculator::calculate(const City& city1, const City& city2) const {
    return std::abs(city2.x - city1.x) + std::abs(city2.y - city1.y);
}
