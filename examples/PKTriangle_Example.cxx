#include <iostream>
#include "PKTriangle.hxx"
#include <cmath>

#include "PKGlobalDef.hxx"

int main(void)
{
    setLoggerLevel("DEBUG");
    PKTriangle triangle(3,3,(4./3.)*atan(1),"SSA");
    std::cout << "Triangle 1:\t";
    triangle.Print();
    PKTriangle triangle2(2*atan(1),(4./3.)*atan(1),15.,"AAS");
    std::cout << "\nTriangle 2:\t";
    triangle2.Print();
    std::cout << "\nIs Right Angled?\t";
    if(triangle2.isRightAngled()){std::cout << "True\n";}
    else{std::cout << "False\n";}
}
