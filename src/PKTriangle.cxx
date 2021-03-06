#include "PKTriangle.hxx"

double CosineRuleSide(double side1, double side2, double angle)
{return pow(pow(side1,2)+pow(side2,2) - 2*side1*side2*cos(angle),0.5);}
double CosineRuleAngle(double side1, double side2, double side3)
{return acos((pow(side1,2)+pow(side2,2)-pow(side3,2))/(2*side1*side2));}
void PKTriangle::calculate_(double par1,double par2,double par3)
{
	if(type_ == "AAS")
	{
		_triangle_logger.Info( "Performing Calculation for Angle-Angle-Side" );
		angles[0] = par1*1.0;
		angles[1] = par2*1.0;
		sides[2] = par3*1.0;
		
		angles[2] = pi - (par1+par2);
		sides[1] = (sides[2]/sin(angles[2]))*sin(angles[1]);
		sides[0] = (sides[2]/sin(angles[2]))*sin(angles[0]);
		
	}
	else
	{
		_triangle_logger.Info( "Performing Calculation for Side-Side-Angle" );
		sides[0] = par1*1.0;
		sides[1] = par2*1.0;
		angles[2] = par3*1.0;

		sides[2] = CosineRuleSide(sides[0],sides[1],angles[2]);
		angles[0] = asin((sin(angles[2])/sides[2])*sides[0]);
		angles[1] = asin((sin(angles[2])/sides[2])*sides[1]);

	}
	_triangle_logger.Debug( "Calculated Angles (%1%,%2%,%3%) and Sides (%4%,%5%,%6%)", std::to_string(angles[0]), std::to_string(angles[1]), std::to_string(angles[2]), std::to_string(sides[0]), std::to_string(sides[1]), std::to_string(sides[2]));
}		
		 
PKTriangle::PKTriangle(double par1,double par2,double par3,std::string opts)
{
	type_ = opts;

	if(type_ != "AAS" && type_ != "SSA")
	{	
		_triangle_logger.Error( "Invalid Type of '%1%', options are 'AAS' or 'SSA'", type_ ); 
		exit(EXIT_FAILURE);
	}
	_triangle_logger.Info( "Initialising Triangle of Type '%1%'", type_ );
	calculate_(par1,par2,par3);
}
void PKTriangle::Print()
{
	std::cout << "PKTriangle_" << type_ << "(ANGLES[" << angles[0] << "," << angles[1] << "," << angles[2] << "]";
	std::cout << ", SIDES[" << sides[0] << "," << sides[1] << "," << sides[2] << "])\n";
}
bool PKTriangle::isRightAngled()
{
	for(int i = 0; i<sizeof(angles);++i){if(angles[i] > 0.5*0.99*pi && angles[i] < 0.5*1.01*pi){return true;}}
	return false;
}
