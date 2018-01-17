/**
  Physics Kit Libary, PKMatrix.cxx
  
  Matrix Class with operations including transpose

  @author  Kristian Zarebski
  @version 1.0.0
  @date last modified 2018-01-14

*/

#include "PKMatrix.hxx"

#include <stdlib.h>

PKMatrix::PKMatrix(){}

void PKMatrix::addRow(PKVar x1_, PKVar x2_,PKVar x3_,PKVar x4_,PKVar x5_,PKVar x6_,PKVar x7_,PKVar x8_,PKVar x9_,PKVar x10_)
{
	_matrix_logger.Info( "Adding New Row to Matrix." );
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
void PKMatrix::addColumn(PKVar x1_, PKVar x2_,PKVar x3_,PKVar x4_,PKVar x5_,PKVar x6_,PKVar x7_,PKVar x8_,PKVar x9_,PKVar x10_)
{
	_matrix_logger.Info( "Adding New Column to Matrix." );
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
	_matrix_logger.Info( "Commencing Matrix Addition..." );
	if(param.elements_.size() != elements_.size() && param.elements_[0].size() != elements_[0].size())
	{
		_matrix_logger.Error( "Cannot Add Matrices with Different Dimensions." );
		exit(EXIT_FAILURE);
	}
	_matrix_logger.Debug( "Constructing Addition Template" );
	_matrix_logger.Debug( "Creating New Columns" );
	std::vector<PKVar> x_;
	for(int m=0;m<elements_[0].size();++m){x_.push_back(PKVar(0,0));}
	_matrix_logger.Debug( "Creating New Rows" );
	std::vector<std::vector<PKVar> > y_;
	for(int n=0;n<elements_.size();++n){y_.push_back(x_);}
	PKMatrix temp(y_);
	_matrix_logger.Debug( "Inserting Calculated Elements into Template" );
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
	_matrix_logger.Info( "Commencing Matrix Subtraction..." );
	if(param.elements_.size() != elements_.size() && param.elements_[0].size() != elements_[0].size())
	{
		_matrix_logger.Error( "Cannot Subtract Matrices with Different Dimensions." );
		exit(EXIT_FAILURE);
	}
	_matrix_logger.Debug( "Constructing Subtraction Template" );
	_matrix_logger.Debug( "Creating New Columns" );
	std::vector<PKVar> x_;
	for(int m=0;m<elements_[0].size();++m){x_.push_back(PKVar(0,0));}
	_matrix_logger.Debug( "Creating New Rows" );
	std::vector<std::vector<PKVar> > y_;
	for(int n=0;n<elements_.size();++n){y_.push_back(x_);}
	PKMatrix temp(y_);
	_matrix_logger.Debug( "Inserting Calculated Elements into Template" );
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
	_matrix_logger.Info( "Calculating Matrix Transpose..." );
	_matrix_logger.Debug( "Constructing Transpose Template" );
	_matrix_logger.Debug( "Creating New Columns" );
	std::vector<PKVar> x_;
	for(int m=0;m<elements_.size();++m){x_.push_back(PKVar(0,0));}
	_matrix_logger.Debug( "Creating New Rows" );
    std::vector<std::vector<PKVar> > y_;
    for(int n=0;n<elements_[0].size();++n){y_.push_back(x_);}
    PKMatrix temp(y_);
	_matrix_logger.Debug( "Inserting Calculated Elements into Template" );
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
	_matrix_logger.Info( "Commencing Matrix Multplication..." );
	_matrix_logger.Debug( "Constructing Multiplication Template" );
	if(param.elements_.size() != elements_[0].size())
	{
		_matrix_logger.Error( "Cannot multiply matrices with set dimensions." );
		exit(EXIT_FAILURE);
	}
	_matrix_logger.Debug( "Creating New Columns" );
	std::vector<PKVar> x_;
    for(int m=0;m<elements_[0].size();++m){x_.push_back(PKVar(0,0));}
	_matrix_logger.Debug( "Creating New Rows" );
    std::vector<std::vector<PKVar> > y_;
    for(int n=0;n<elements_.size();++n){y_.push_back(x_);}
    PKMatrix temp(y_);
	_matrix_logger.Debug( "Inserting Calculated Elements into Template" );
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
	_matrix_logger.Info( "Calculating Matrix Trace..." );
	PKVar x_(0,0);

	if(elements_[0].size() != elements_.size())
	{
		_matrix_logger.Error( "Trace can only be calculated for a square matrix!" );
		exit(EXIT_FAILURE);
	}

	_matrix_logger.Debug( "Adding Trace Components" );

	for(int i=0; i<elements_.size(); ++i)
	{
		x_ = x_ + elements_[i][i];
	}
	return x_;
}
