#include <iostream>
#include "PKMatrix.h"

int main(void)
{
	PKMatrix a();

	a.addRow(PKVar(12.,0.1),PKVar(15.,0.2),PKVar(11.,0.3));
	a.addRow(PKVar(5.,0.2),PKVar(7.,0.1),PKVar(9.,0.3));
	a.addRow(PKVar(10.,0.1),PKVar(5.,0.1),PKVar(8.,0.1));

	a.Print();

}
