#include "Trapezoid.h"

int Trapezoid::numTrap = 0;

Trapezoid::~Trapezoid() {
  numTrap--;
  std::cout << "Trapezoid Destructor " << this->getColor() << "\n";
}

Trapezoid::Trapezoid(double a, double b, double d, string color)
  :ColoredShape(color), a_base(a), b_base(b), height(d)
{
  numTrap++;
}

double
Trapezoid::getArea(void) {
  return height * (a_base+b_base)/2;
}

void 
Trapezoid::printArea(std::ostream &s) {
  s << "Trapezoid: color: " << this->getColor() << ", area: "
    << height * (a_base + b_base)/2 << " numRect: " << numTrap << "\n";
}

