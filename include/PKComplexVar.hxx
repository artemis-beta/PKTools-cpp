#ifndef PKCOMPLEXVAR_H
#define PKCOMPLEXVAR_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

class PKComplexVar
{
	private:
		float _real;
		float _imagin;
		float _modulus;
		float _arg;
	
	public:
		void _setReal(float);
		void _setImag(float);
		float getRe();
		float getIm();
		float getMod();
		float getArg();
		std::string returnString(int opt=0);
		void Print(int opt=0, int precision=3);

	PKComplexVar(float, float);
	PKComplexVar operator + (PKComplexVar);
	PKComplexVar operator - (PKComplexVar);
	PKComplexVar operator / (PKComplexVar);
	PKComplexVar operator / (int);
	PKComplexVar operator / (float);
	PKComplexVar operator / (double);
	PKComplexVar operator * (PKComplexVar);
	PKComplexVar operator * (int);
	PKComplexVar operator * (float);
	PKComplexVar operator * (double);
	bool operator == (PKComplexVar);
	bool operator != (PKComplexVar);
	PKComplexVar Conjugate();
};

#endif
