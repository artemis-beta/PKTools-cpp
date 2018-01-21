#include <iostream>
#include "PKCompMatrix.hxx"

#include "PKGlobalDef.hxx"

int main(void)
{
	PKCompMatrix a,b;

	std::cout << "Construct a 3x3 matrix:\n";
	a.addRow(PKComplexVar(12.,1),PKComplexVar(15.,2),PKComplexVar(11.,3));
	a.addRow(PKComplexVar(5.,2),PKComplexVar(7.,0),PKComplexVar(9.,5));
	a.addRow(PKComplexVar(10.,1),PKComplexVar(5.,2),PKComplexVar(8.,0));

	a.Print();
	
	std::cout << "Construct another 3x3 matrix:\n";
	b.addRow(PKComplexVar(2.,1),PKComplexVar(1.,2),PKComplexVar(1.,0));
	b.addRow(PKComplexVar(6.,0),PKComplexVar(5.,1),PKComplexVar(3.,3));
	b.addRow(PKComplexVar(0.,1),PKComplexVar(2.,0),PKComplexVar(1.,0));

	b.Print();

	std::cout << "Add them together:\n";
	PKCompMatrix c;
	c = a+b;
	c.Print();
	std::cout << "Multiply them together:\n";
	PKCompMatrix f;
	f = a*b;
	f.Print();
	std::cout << "Take the Transpose:\n";;
	c.Transpose().Print();
	std::cout << "The Trace is:\n";
	c.Trace().Print();

	std::cout << "\nLets Try a 2x3 matrix\n";
	PKCompMatrix d;
	d.addRow(PKComplexVar(1.4,0),PKComplexVar(5.8,2));
	d.addRow(PKComplexVar(3.2,1),PKComplexVar(1.5,0));
	d.addRow(PKComplexVar(6.0,0),PKComplexVar(5.6,1));
	d.Print();
	std::cout << "Take the Transpose:\n";
	d.Transpose().Print();
	std::cout << "Can't do the Trace!\n";
	d.Trace();
}
