#include <iostream>
#include "PKVar.h"

int main(void)
{
	PKVar x(100.,10.);
	PKVar y(56.,0.34);

	PKVar z = x + y;
	z.Print(); 
	std::cout<< "\n";

}
	
