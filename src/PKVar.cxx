#include "PKVar.hxx"

#include <cmath>
#include <iostream>

PKVar::PKVar()
{value_ = 0; error_ = 0;}
PKVar::PKVar(float value, float error)
{
	value_ = value;
	error_ = error;
}
float PKVar::getVal(){return value_;}
float PKVar::getError(){return error_;}
void PKVar::Print(){std::cout << value_ << " +/- " << error_;}
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
	temp.error_ = pow(pow(error_,2) + pow(param.error_,2),0.5);
	return temp;
}
PKVar PKVar::operator * (PKVar param)
{
	PKVar temp;
	temp.value_ = value_ * param.value_;
	temp.error_ = pow(pow(param.value_*error_,2)+pow(value_*param.error_,2),0.5);
	return temp;
}
PKVar PKVar::operator / (PKVar param)
{
	PKVar temp;
	temp.value_ = value_ / param.value_;
	temp.error_ = pow(pow(error_/param.value_,2)+pow(value_*param.error_,2)*pow(param.value_,-4),0.5);
	return temp;
}
PKVar PKVar::Power(float x)
{
	PKVar temp;
	if(value_ == 0 && x < 1)
	{
		return temp;
	}
	temp.value_ = pow(value_,x);
	temp.error_ = x*pow(value_,x-1)*error_;
	return temp;
}
PKVar PKVar::Sqrt()
{
	return Power(0.5);
} 
