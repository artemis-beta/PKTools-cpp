#ifndef __PKMATRIX__
#define __PKMATRIX__

#include "PKVar.h"
#include <iostream>
#include <vector>

class PKMatrix {

	private: 
		std::vector<std::vector<PKVar> > elements_;
	public:
		PKMatrix();
		PKMatrix(std::vector<std::vector<PKVar> > x_);
		void Print();
		void addRow(PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar);
		void addColumn(PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar);

};
PKMatrix::PKMatrix()
PKMatrix::PKMatrix(std::vector<std::vector<PKVar> > x_)
{
	elements = x_;
}
void PKMatrix::addRow(PKVar x1_=PKVar(0,0),PKVar x2_=PKVar(0,0),PKVar x3_=PKVar(0,0),PKVar x4_=PKVar(0,0),PKVar x5_=PKVar(0,0),PKVar x6_=PKVar(0,0),PKVar x7_=PKVar(0,0),PKVar x8_=PKVar(0,0),PKVar x9_=PKVar(0,0),PKVar x10_=PKVar(0,0))
{
	std::vector<PKVar> temp[10] = {x1_,x2_,x3_,x4_,x5_,x6_,x7_,x8_,x9_,x10_};
	x_.push_back(temp);
}
void PKMatrix::addColumn(PKVar x1_=PKVar(0,0),PKVar x2_=PKVar(0,0),PKVar x3_=PKVar(0,0),PKVar x4_=PKVar(0,0),PKVar x5_=PKVar(0,0),PKVar x6_=PKVar(0,0),PKVar x7_=PKVar(0,0),PKVar x8_=PKVar(0,0),PKVar x9_=PKVar(0,0),PKVar x1PKVar(0,0)_=PKVar(0,0)
{
	PKVar temp[10] = {x1_,x2_,x3_,x4_,x5_,x6_,x7_,x8_,x9_,x10_};
	for(int i=0; i<vector.size();++i)
	{
		x_[i].push_back(temp[i]);
	}
}
void PKMatrix::Print()
{
	std::cout << "[";
	for(int i=0;i<x_.size();++i)
	{
		std::cout << "(";
		for(int j=0;j<x_[0].size())
		{
			std::cout << x_[i][j] << ",";
		}
		std::cout << ")\n";
	}
	std::cout << "]\n";
}
#endif
