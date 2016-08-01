#include <iostream>
#include "PKLorentzVector.h"

int main(void)
{
	PKLorentzVector a(PKVar(493.,2.),PKVar(-5.6,0.1),PKVar(1.8,0.1),PKVar(0,0));
	PKLorentzVector b(PKVar(511.,3.),PKVar(5.6,0.1),PKVar(-1.8,0.1),PKVar(0,0));
	std::cout << "Lorentz Vector 1: "; a.Print();
	std::cout << "\nLorentz Vector 2: "; b.Print();
	std::cout << "\nAddition: ";
	PKLorentzVector c = a+b;
	c.Print();
	std::cout <<"\n";
}
