#ifndef _TRAPEZOID
#define _TRAPEZOID

#include "ColoredShape.h"

class Trapezoid: public ColoredShape {
 public:
  Trapezoid(double a, double b, double h, string color);
  ~Trapezoid();
  double getArea(void);
  void printArea(std::ostream &s);  

 protected:

 private:
  double a_base, b_base, height;
  static int numTrap;
};

#endif // _TRAPEZOID

  
