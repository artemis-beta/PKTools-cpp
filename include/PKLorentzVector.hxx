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
		PKLorentzVector(float x0_,float x1_,float x2_,float x3_,float x0err_,float x1err_,float x2err_, float x3err_);
		PKVar getMagnitude();
		PKLorentzVector operator + (PKLorentzVector);
		PKLorentzVector operator - (PKLorentzVector);
		void Print();
};
#endif
