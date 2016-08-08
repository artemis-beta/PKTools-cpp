#ifndef __PKMATRIX__
#define __PKMATRIX__

#include "PKVar.h"
#include <iostream>
#include <vector>
#include <cassert>

class PKMatrix {

	private: 
		std::vector<std::vector<PKVar> > elements_;
	public:
		PKMatrix(){};
		PKMatrix(std::vector<std::vector<PKVar> > x_){elements_ = x_;}
		void Print();
		void addRow(PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar);
		void addColumn(PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar,PKVar);
		PKMatrix operator + (PKMatrix);
		PKMatrix operator - (PKMatrix);
		PKMatrix operator * (PKMatrix);
		PKMatrix Transpose();
		PKVar Trace();
};
void PKMatrix::addRow(PKVar x1_=PKVar(0,1E-314),PKVar x2_=PKVar(0,1E-314),PKVar x3_=PKVar(0,1E-314),PKVar x4_=PKVar(0,1E-314),PKVar x5_=PKVar(0,1E-314),PKVar x6_=PKVar(0,1E-314),PKVar x7_=PKVar(0,1E-314),PKVar x8_=PKVar(0,1E-314),PKVar x9_=PKVar(0,1E-314),PKVar x10_=PKVar(0,1E-314))
{
	std::vector<PKVar> temp;
	temp.push_back(x1_);
	if(x2_.GetError() != 1E-314){temp.push_back(x2_);}
	if(x3_.GetError() != 1E-314){temp.push_back(x3_);}
	if(x4_.GetError() != 1E-314){temp.push_back(x4_);}
	if(x5_.GetError() != 1E-314){temp.push_back(x5_);}
	if(x6_.GetError() != 1E-314){temp.push_back(x6_);}
	if(x7_.GetError() != 1E-314){temp.push_back(x7_);}
	if(x8_.GetError() != 1E-314){temp.push_back(x8_);}
	if(x9_.GetError() != 1E-314){temp.push_back(x9_);}
	if(x10_.GetError() != 1E-314){temp.push_back(x10_);}
	elements_.push_back(temp);
}
void PKMatrix::addColumn(PKVar x1_=PKVar(0,1E-314),PKVar x2_=PKVar(0,1E-314),PKVar x3_=PKVar(0,1E-314),PKVar x4_=PKVar(0,1E-314),PKVar x5_=PKVar(0,1E-314),PKVar x6_=PKVar(0,1E-314),PKVar x7_=PKVar(0,1E-314),PKVar x8_=PKVar(0,1E-314),PKVar x9_=PKVar(0,1E-314),PKVar x10_=PKVar(0,1E-314))
{
	PKVar temp[10] = {x1_,x2_,x3_,x4_,x5_,x6_,x7_,x8_,x9_,x10_};
	for(int i=0; i<elements_.size();++i)
	{
		elements_[i].push_back(temp[i]);
	}
}
void PKMatrix::Print()
{
	std::cout << "[";
	for(int i=0;i<elements_.size();++i)
	{
		std::cout << "(";
		for(int j=0;j<elements_[0].size();++j)
		{
			elements_[i][j].Print();
			if(j+1 < elements_[0].size()){std::cout  << ",";}
			else if(i+1 < elements_.size()){std::cout << ")\n";}
			else{std::cout << ")";}
		}
	}
	std::cout << "]\n";
}
PKMatrix PKMatrix::operator + (PKMatrix param)
{
	if(param.elements_.size() != elements_.size() && param.elements_[0].size() != elements_[0].size())
	{
		std::cout << "ERROR: Cannot add matrices of varying dimensions\n";
		return PKMatrix();
	}
	std::vector<PKVar> x_;
	for(int m=0;m<elements_[0].size();++m){x_.push_back(PKVar(0,0));}
	std::vector<std::vector<PKVar> > y_;
	for(int n=0;n<elements_.size();++n){y_.push_back(x_);}
	PKMatrix temp(y_);
	for(int i=0;i<temp.elements_.size();++i)
	{
		for(int j=0;j<temp.elements_[0].size();++j)
		{
			temp.elements_[i][j] = elements_[i][j] + param.elements_[i][j];	
		}
	}
	return temp;
}
PKMatrix PKMatrix::operator - (PKMatrix param)
{
	if(param.elements_.size() != elements_.size() && param.elements_[0].size() != elements_[0].size())
	{
		std::cout << "ERROR: Cannot subtract matrices of varying dimensions\n";
		return PKMatrix();
	}
	std::vector<PKVar> x_;
	for(int m=0;m<elements_[0].size();++m){x_.push_back(PKVar(0,0));}
	std::vector<std::vector<PKVar> > y_;
	for(int n=0;n<elements_.size();++n){y_.push_back(x_);}
	PKMatrix temp(y_);
	for(int i=0;i<temp.elements_.size();++i)
	{
		for(int j=0;j<temp.elements_[0].size();++j)
		{
			temp.elements_[i][j] = elements_[i][j] - param.elements_[i][j];	
		}
	}
	return temp;
}
PKMatrix PKMatrix::Transpose()
{
	std::vector<PKVar> x_;
	for(int m=0;m<elements_.size();++m){x_.push_back(PKVar(0,0));}
        std::vector<std::vector<PKVar> > y_;
        for(int n=0;n<elements_[0].size();++n){y_.push_back(x_);}
        PKMatrix temp(y_);
        for(int i=0;i<temp.elements_.size();++i)
        {
                for(int j=0;j<temp.elements_[0].size();++j)
                {
                        temp.elements_[i][j] = elements_[j][i];
                }
        }
        return temp;
}
PKMatrix PKMatrix::operator * (PKMatrix param)
{
	if(param.elements_.size() != elements_[0].size())
	{
		std::cout << "ERROR: cannot multiply matrices with set dimensions\n";
		return PKMatrix();
	}

	std::vector<PKVar> x_;
        for(int m=0;m<elements_[0].size();++m){x_.push_back(PKVar(0,0));}
        std::vector<std::vector<PKVar> > y_;
        for(int n=0;n<elements_.size();++n){y_.push_back(x_);}
        PKMatrix temp(y_);
	for(int i=0;i<temp.elements_.size();++i)
        {
                for(int j=0;j<temp.elements_[0].size();++j)
                {
			 
                        for(int l=0;l<elements_[0].size();++l)
			{
				temp.elements_[i][j] = temp.elements_[i][j] + elements_[i][l]*param.elements_[l][j];
			}
                }
        }
        return temp;
}
PKVar PKMatrix::Trace()
{
	PKVar x_(0,0);

	if(elements_[0].size() != elements_.size())
	{
		std::cout << "ERROR: Trace can only be calculated for a square matrix!\n";
		return PKVar(0,0);
	}
	for(int i=0; i<elements_.size(); ++i)
	{
		x_ = x_ + elements_[i][i];
	}
	return x_;
} 
#endif
 
