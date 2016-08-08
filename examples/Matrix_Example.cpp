#include <iostream>
#include "PKMatrix.h"

int main(void)
{
	PKMatrix a,b;

	std::cout << "Construct a 3x3 matrix:\n";
	a.addRow(PKVar(12.,0.1),PKVar(15.,0.2),PKVar(11.,0.3));
	a.addRow(PKVar(5.,0.2),PKVar(7.,0.1),PKVar(9.,0.3));
	a.addRow(PKVar(10.,0.1),PKVar(5.,0.1),PKVar(8.,0.1));

	a.Print();
	
	std::cout << "Construct another 3x3 matrix:\n";
	b.addRow(PKVar(2.,0.1),PKVar(1.,0.2),PKVar(1.,0.3));
	b.addRow(PKVar(6.,0.2),PKVar(5.,0.1),PKVar(3.,0.3));
	b.addRow(PKVar(0.,0.1),PKVar(2.,0.1),PKVar(1.,0.1));

	b.Print();

	std::cout << "Add them together:\n";
	PKMatrix c;
	c = a+b;
	c.Print();
		
}
