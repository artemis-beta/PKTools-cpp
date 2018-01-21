#include "PKConstMatrix.hxx"

int main(void)
{
	std::cout << "Let us check the Gamma Matrix Identities:\n";	
	std::cout << "IDENTITY 1: i*Dirac(0)*Dirac(1)*Dirac(2)*Dirac(3) = Dirac(5)\n";
	PKCompMatrix temp = Dirac(0)*Dirac(1)*Dirac(2)*Dirac(3)*PKComplexVar(0,1);
	std::cout << "Calculation: "<< std::endl;
	temp.Print();
	std::cout << "Dirac(5): " <<std::endl;
	temp = Dirac(5);
	temp.Print();
	bool b = temp == Dirac(5);
	std::cout << "Result Bool = " << b << std::endl;
}
