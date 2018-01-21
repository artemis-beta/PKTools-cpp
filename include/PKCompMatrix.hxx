#ifndef __PKMATRIX_HXX__
#define __PKMATRIX_HXX__

#include "PKComplexVar.hxx"
#include "PKLogger.hxx"

#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <cmath>
#include <stdlib.h>
#include <math.h>

class PKCompMatrix {

	private: 
		std::vector<std::vector<PKComplexVar> > elements_;
		PKLogger _matrix_logger = PKLogger( "PKCOMPMATRIX" );
	public:
		PKCompMatrix(){};
		PKCompMatrix(std::vector<std::vector<PKComplexVar> > x_){elements_ = x_;}
		PKCompMatrix blankMatrix();
		void Print(int precision=3);
		void addRow(PKComplexVar x1_=PKComplexVar(0,nan("")),PKComplexVar x2_=PKComplexVar(0,nan("")),PKComplexVar x3_=PKComplexVar(0,nan("")),PKComplexVar x4_=PKComplexVar(0,nan("")),PKComplexVar x5_=PKComplexVar(0,nan("")),PKComplexVar x6_=PKComplexVar(0,nan("")),PKComplexVar x7_=PKComplexVar(0,nan("")),PKComplexVar x8_=PKComplexVar(0,nan("")),PKComplexVar x9_=PKComplexVar(0,nan("")),PKComplexVar x10_=PKComplexVar(0,nan("")));
		void addColumn(PKComplexVar x1_=PKComplexVar(0,nan("")),PKComplexVar x2_=PKComplexVar(0,nan("")),PKComplexVar x3_=PKComplexVar(0,nan("")),PKComplexVar x4_=PKComplexVar(0,nan("")),PKComplexVar x5_=PKComplexVar(0,nan("")),PKComplexVar x6_=PKComplexVar(0,nan("")),PKComplexVar x7_=PKComplexVar(0,nan("")),PKComplexVar x8_=PKComplexVar(0,nan("")),PKComplexVar x9_=PKComplexVar(0,nan("")),PKComplexVar x10_=PKComplexVar(0,nan("")));
		PKCompMatrix operator + (PKCompMatrix);
		PKCompMatrix operator - (PKCompMatrix);
		PKCompMatrix operator * (PKCompMatrix);
		PKCompMatrix operator * (PKComplexVar);
		PKCompMatrix operator * (float);
		bool operator == (PKCompMatrix);
		bool operator != (PKCompMatrix);
		PKCompMatrix Transpose();
		PKComplexVar Trace();
};
#endif
