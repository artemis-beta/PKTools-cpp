#ifndef __PKMATRIX_HXX__
#define __PKMATRIX_HXX__

#include "PKVar.hxx"
#include "PKLogger.hxx"

#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

class PKMatrix {

	private: 
		std::vector<std::vector<PKVar> > elements_;
		PKLogger _matrix_logger = PKLogger( "PKMATRIX" );
	public:
		PKMatrix();
		PKMatrix(std::vector<std::vector<PKVar> > x_){elements_ = x_;}
		void Print();
		void addRow(PKVar x1_=PKVar(0,nan("")),PKVar x2_=PKVar(0,nan("")),PKVar x3_=PKVar(0,nan("")),PKVar x4_=PKVar(0,nan("")),PKVar x5_=PKVar(0,nan("")),PKVar x6_=PKVar(0,nan("")),PKVar x7_=PKVar(0,nan("")),PKVar x8_=PKVar(0,nan("")),PKVar x9_=PKVar(0,nan("")),PKVar x10_=PKVar(0,nan("")));
		void addColumn(PKVar x1_=PKVar(0,nan("")),PKVar x2_=PKVar(0,nan("")),PKVar x3_=PKVar(0,nan("")),PKVar x4_=PKVar(0,nan("")),PKVar x5_=PKVar(0,nan("")),PKVar x6_=PKVar(0,nan("")),PKVar x7_=PKVar(0,nan("")),PKVar x8_=PKVar(0,nan("")),PKVar x9_=PKVar(0,nan("")),PKVar x10_=PKVar(0,nan("")));
		PKMatrix operator + (PKMatrix);
		PKMatrix operator - (PKMatrix);
		PKMatrix operator * (PKMatrix);
		PKMatrix Transpose();
		PKVar Trace();
};
#endif
