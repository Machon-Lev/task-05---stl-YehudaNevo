
#ifndef TASK06_DISTANCECALCULATOR_H
#define TASK06_DISTANCECALCULATOR_H

#include "City.h"

class DistanceCalculator {
public:
    virtual double calculate(const City& city1, const City& city2) const = 0; // pure virtual function
    virtual ~DistanceCalculator() {}


};

class EuclideanCalculator : public DistanceCalculator {
public:
    double calculate(const City& city1, const City& city2) const override;
};

class ChebyshevCalculator : public DistanceCalculator {
public:
    double calculate(const City& city1, const City& city2) const override;
};

class ManhattanCalculator : public DistanceCalculator {
public:
    double calculate(const City& city1, const City& city2) const override;
};




#endif //TASK06_DISTANCECALCULATOR_H
