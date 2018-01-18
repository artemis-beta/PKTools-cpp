#ifndef __PKTRIANGLE__
#define __PKTRIANGLE__

#include <iostream>
#include <string>
#include <cmath>
#include "PKLogger.hxx"

const double pi = 4*atan(1);

class PKTriangle {

	private:
		std::string type_;
		double sides[3];
		double angles[3];
		void calculate_(double par1,double par2, double par3);
		PKLogger _triangle_logger = PKLogger("PKTRIANGLE");
	public:
		PKTriangle(double par1,double par2,double par3,std::string opts);	

		double* GetAngles(){return angles;}
		double* GetSides(){return sides;}
		bool isRightAngled();
		void Print();		
};

#endif

