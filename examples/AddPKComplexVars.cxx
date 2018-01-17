#include <iostream>
#include "PKComplexVar.hxx"

int main(void)
{
	PKComplexVar x = PKComplexVar(10,2);
	PKComplexVar y = PKComplexVar(5,1);
	std::cout << "x = " << x.returnString() << std::endl;
	std::cout << "y = " << y.returnString() << std::endl;
	PKComplexVar z = x+y;
	std::cout << "x + y = " << z.returnString() << std::endl;
	PKComplexVar v = x-y;
	std::cout << "x - y = " << v.returnString() << std::endl;
	PKComplexVar w = x*y;
	std::cout << "x * y = " << w.returnString() << std::endl;
	PKComplexVar u = x/y;
	std::cout << "x / y = " << u.returnString() << std::endl;
	PKComplexVar t = y*20;
	std::cout << "y*20 = " << t.returnString() << std::endl;
	PKComplexVar s = x/4.;
	std::cout << "x / 4. = " << s.returnString() << std::endl;
}
