#include "Rectangle.h"
<<<<<<< HEAD
#include "Trapezoid.h"
=======
#include "Ellipse.h"
>>>>>>> upstream/master

int main(int argc, char **argv) {
  Rectangle s1(1.0, 2.0, "red");
  ColoredShape *s2 = new Rectangle(3.0, 1.0, "blue");  
<<<<<<< HEAD
  Trapezoid s3(1.0,1.0,1.0,"orange");
  ColoredShape *s4 = new Trapezoid(3.0, 2.0, 2.0, "pink");

  s1.printArea(std::cout);
  s2->printArea(std::cout);
  s3.printArea(std::cout);
  s4->printArea(std::cout);
  delete s2;
  delete s4;
=======
  ColoredShape *s3 = new Ellipse(3.0,2.0,"purple");
  //  Shape *s4 = new Square(3.0, "pink");

  s1.printArea(std::cout);
  s2->printArea(std::cout);
  s3->printArea(std::cout);
  //  s4->printArea(std::cout);

  delete s2;
  delete s3;
>>>>>>> upstream/master
  return 0;
}


