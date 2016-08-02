//Joel C. Swallow 2.8.16////////////////////////////////////////////////////////////////////////////
#ifndef __PKRECTANGLE__
#define __PKRECTANGLE__

#include <string>
#include <cmath>

//PKRectange::PKRectangle(double par1, double par2){}

class PKRectangle {

	private:
		double sides[4];
		double angles[2];

	public:
		PKRectangle(double par1,double par2);
//		PKRectangle~{}
		void Calculate(double par1, double par2);
		double* GetSides();
		double* GetAngles();
		void Print();		
};

#endif

