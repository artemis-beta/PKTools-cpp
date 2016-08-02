#ifndef __PKLORENTZVECTOR__
#define __PKLORENTZVECTOR__

#include "PKVar.h"

class PKLorentzVector {

	private:
		PKVar X[4];
		PKVar Magn_;
	public:
		PKLorentzVector();
		PKLorentzVector(PKVar x0_,PKVar x1_,PKVar x2_, PKVar x3_);
		PKLorentzVector(double x0_,double x1_,double x2_,double x3_,double x0err_,double x1err_,double x2err_, double x3err_);
		PKVar getMagnitude();
		PKLorentzVector operator + (PKLorentzVector);
		PKLorentzVector operator - (PKLorentzVector);
		void Print();
};
PKLorentzVector::PKLorentzVector()
{
	for(int i=0;i<=3;++i){X[i] = PKVar(0,0);}
        PKVar Magn2_ = X[0]*X[0] - X[1]*X[1] - X[2]*X[2] - X[3]*X[3];
        Magn_ = Magn2_.Sqrt();
}
PKLorentzVector::PKLorentzVector(PKVar x0_,PKVar x1_,PKVar x2_, PKVar x3_)
{
	X[0] = x0_,X[1] = x1_,X[2] = x2_, X[3] = x3_;
	PKVar Magn2_ = X[0]*X[0] - X[1]*X[1] - X[2]*X[2] - X[3]*X[3];
        Magn_ = Magn2_.Sqrt();
}
PKLorentzVector::PKLorentzVector(double x0_,double x1_,double x2_,double x3_,double x0err_=0,double x1err_=0,double x2err_=0, double x3err_=0)
{
	X[0] = PKVar(x0_,x0err_),X[1] = PKVar(x1_,x1err_),X[2] = PKVar(x2_,x2err_);
	X[3] = PKVar(x3_,x3err_);
	PKVar Magn2_ = X[0]*X[0] - X[1]*X[1] - X[2]*X[2] - X[3]*X[3];
	Magn_ = Magn2_.Sqrt();
}
PKVar PKLorentzVector::getMagnitude(){return Magn_;}

PKLorentzVector PKLorentzVector::operator + (PKLorentzVector param)
{
	PKLorentzVector temp;
	for(int i=0;i<=3;++i){temp.X[i] = X[i] + param.X[i];}
	return temp;
}
PKLorentzVector PKLorentzVector::operator - (PKLorentzVector param)
{
	PKLorentzVector temp;
	for(int i=0;i<=3;++i){temp.X[i] = X[i] - param.X[i];}
	return temp;
}
void PKLorentzVector::Print()
{
	std::cout << "("; X[0].Print(); std::cout  << ","; X[1].Print();
	std::cout << ","; X[2].Print(); std::cout  << ","; X[3].Print();
	std::cout <<  ")";
}
#endif
