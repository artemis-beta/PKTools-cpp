#include <iostream>
#include "PKTriangle.h"

int main(void)
{
    PKTriangle triangle(100,150,0.75,"SSA");
    triangle.Print();
    PKTriangle triangle2(0.56,0.75,150,"AAS");
    triangle2.Print();
}
