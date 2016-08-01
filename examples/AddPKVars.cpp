#include <iostream>
#include "PKVar.h"

int main(void)
{
	PKVar x(100.,10.);
	PKVar y(56.,0.34);

	std::cout << "Vector 1: ";
	x.Print();
	std::cout << "\nVector 2: ";
	y.Print();
	std::cout << "\n\nAddition: ";
	PKVar z = x + y;
	z.Print(); 
	std::cout<< "\n";
	z = x - y;
	std::cout << "\nSubtraction: ";
	z.Print();
	z = x*y;
	std::cout << "\nMultiplication: ";
	z.Print();
	z = x/y;
	std::cout << "\nDivision: ";
	z.Print();
	std::cout << "\n";

}
	
