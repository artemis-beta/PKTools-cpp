#include <iostream>
#include <cmath>
#include "PKTriangle.h"
void PKTriangle::calculate_(double par1,double par2,double par3)
{
	if(type_ == "AAS")
	{
		angles[0] = par1;
		angles[1] = par2;
		sides[2] = par3;
		
		angles[2] = pi - (par1+par2);
		sides[1] = (sides[2]/sin(angles[2]))*sin(angles[1]);
		sides[0] = (sides[2]/sin(angles[2]))*sin(sides[0]);
	}
	else{
		sides[0] = par1;
		sides[1] = par2;
		angles[2] = par3;

		sides[2] = pow(sides[0],2)+pow(sides[1],2) - 2*sides[0]*sides[1]*cos(angles[2]);
		angles[0] = asin((angles[2]/sides[2])*sides[0]);
		angles[1] = asin((angles[2]/sides[2])*sides[1]);
	}
}		
		 
PKTriangle::PKTriangle(double par1,double par2,double par3,std::string opts)
{
	type_ = opts;

	if(type_ != "AAS" && type_ != "SSA")
	{	
		std::cout << "ERROR: Invalid Type of '" << type_ << "', options are 'AAS' or 'SSA'\n"; 
	}
	calculate_(par1,par2,par3);
}
void PKTriangle::Print()
{
	std::cout << "PKTriangle_" << type_ << "(ANGLES[" << angles[0] << "," << angles[1] << "," << angles[2] << "]";
	std::cout << ", SIDES[" << sides[0] << "," << sides[1] << "," << sides[2] << "])\n";
}
double* PKTriangle::GetAngles(){return angles;}
double* PKTriangle::GetSides(){return sides;}
