#ifndef __PKVAR__
#define __PKVAR__

#include <cmath>

class PKVar {

	private:
		double value_;
		double error_;
	public:
		double GetVal();
		double GetError();
		void Print();
		PKVar(double value, double error);
		PKVar();
		PKVar operator + (PKVar);
		PKVar operator - (PKVar);

};
PKVar::PKVar()
{value_ = 0; error_ = 0;}
PKVar::PKVar(double value, double error)
{
	value_ = value;
	error_ = error;
}
double PKVar::GetVal(){return value_;}
double PKVar::GetError(){return error_;}
void PKVar::Print(){std::cout << value_ << " +/- " << error_ << std::endl;}
PKVar PKVar::operator + (PKVar param)
{
	PKVar temp;
	temp.value_ = value_ + param.value_;
	temp.error_ = pow(pow(error_,2)+pow(param.error_,2),0.5);
	return temp;
}
PKVar PKVar::operator - (PKVar param)
{
	PKVar temp;
	temp.value_ = value_ - param.value_;
	temp.error_ = error_ + param.error_;
	return temp;
}
#endif
