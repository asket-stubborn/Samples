#include <iostream>
#include "complex.h"
int main() {

    double real1, image1,real2,image2;
    real1 = 10; image1 = 2; real2 = 8, image2 = 5;
    Complex *a=  new Complex(real1,image1);
    Complex *b = new Complex(real2);
    std::cout << " abs a" << a->abs();
    *a+=*b;
    std::cout << "\n";
    std::cout << "sum" << a->getReal() << " " << a->getImag();
    std::cout << a;
    a->setReal(20);
    a->setImag(10);
    if (a==b) std::cout << "true";
    else std::cout << "false";
    if (a!=b) std::cout << "true";
    else std::cout << "false";
    return 0;
}