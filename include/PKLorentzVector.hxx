#ifndef __PKLORENTZVECTOR__
#define __PKLORENTZVECTOR__

#include "PKVar.hxx"
#include <iostream>

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
#endif
