#ifndef __PKMATRIX_HXX__
#define __PKMATRIX_HXX__

#include "PKVar.hxx"
#include "PKLogger.hxx"

#include <iostream>
#include <vector>
#include <cassert>

class PKMatrix {

	private: 
		std::vector<std::vector<PKVar> > elements_;
		PKLogger _matrix_logger = PKLogger( "PKMATRIX" );
	public:
		PKMatrix();
		PKMatrix(std::vector<std::vector<PKVar> > x_){elements_ = x_;}
		void Print();
		void addRow(PKVar x1_=PKVar(0,1E-314),PKVar x2_=PKVar(0,1E-314),PKVar x3_=PKVar(0,1E-314),PKVar x4_=PKVar(0,1E-314),PKVar x5_=PKVar(0,1E-314),PKVar x6_=PKVar(0,1E-314),PKVar x7_=PKVar(0,1E-314),PKVar x8_=PKVar(0,1E-314),PKVar x9_=PKVar(0,1E-314),PKVar x10_=PKVar(0,1E-314));
		void addColumn(PKVar x1_=PKVar(0,1E-314),PKVar x2_=PKVar(0,1E-314),PKVar x3_=PKVar(0,1E-314),PKVar x4_=PKVar(0,1E-314),PKVar x5_=PKVar(0,1E-314),PKVar x6_=PKVar(0,1E-314),PKVar x7_=PKVar(0,1E-314),PKVar x8_=PKVar(0,1E-314),PKVar x9_=PKVar(0,1E-314),PKVar x10_=PKVar(0,1E-314));
		PKMatrix operator + (PKMatrix);
		PKMatrix operator - (PKMatrix);
		PKMatrix operator * (PKMatrix);
		PKMatrix Transpose();
		PKVar Trace();
};
#endif
