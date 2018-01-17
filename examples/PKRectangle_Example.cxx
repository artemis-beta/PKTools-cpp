//Joel C. Swallow 2.8.16////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "PKRectangle.h"
//#include "PKRectangle.cpp"

int main(void){
    PKRectangle Rectangle1(2.0,5.0);	//JCS --> object PKRectangle with input parameters 2.0 and 5.0 (inputs are doubles)
    Rectangle1.Print();	//Print the result
    PKRectangle Rectangle2(10.0,15.0);
    Rectangle2.Print();
    PKRectangle Rectangle3(5.0,5.0);
    Rectangle3.Print();
    PKRectangle Rectangle4(12.0,7.0);
    Rectangle4.Print();
}
