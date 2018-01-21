/**
  Physics Kit Libary, PKCompMatrix.cxx
  
  Matrix Class with operations including transpose

  @author  Kristian Zarebski
  @version 1.0.0
  @date last modified 2018-01-14

*/

#include "PKCompMatrix.hxx"

void PKCompMatrix::addRow(PKComplexVar x1_, PKComplexVar x2_,PKComplexVar x3_,PKComplexVar x4_,PKComplexVar x5_,PKComplexVar x6_,PKComplexVar x7_,PKComplexVar x8_,PKComplexVar x9_,PKComplexVar x10_)
{
	_matrix_logger.Info( "Adding New Row to Matrix." );
	std::vector<PKComplexVar> temp;
	temp.push_back(x1_);
	if(!std::isnan(x2_.getIm())){temp.push_back(x2_);}
	if(!std::isnan(x3_.getIm())){temp.push_back(x3_);}
	if(!std::isnan(x4_.getIm())){temp.push_back(x4_);}
	if(!std::isnan(x5_.getIm())){temp.push_back(x5_);}
	if(!std::isnan(x6_.getIm())){temp.push_back(x6_);}
	if(!std::isnan(x7_.getIm())){temp.push_back(x7_);}
	if(!std::isnan(x8_.getIm())){temp.push_back(x8_);}
	if(!std::isnan(x9_.getIm())){temp.push_back(x9_);}
	if(!std::isnan(x10_.getIm())){temp.push_back(x10_);}
	elements_.push_back(temp);
}
void PKCompMatrix::addColumn(PKComplexVar x1_, PKComplexVar x2_,PKComplexVar x3_,PKComplexVar x4_,PKComplexVar x5_,PKComplexVar x6_,PKComplexVar x7_,PKComplexVar x8_,PKComplexVar x9_,PKComplexVar x10_)
{
	_matrix_logger.Info( "Adding New Column to Matrix." );
	PKComplexVar temp[10] = {x1_,x2_,x3_,x4_,x5_,x6_,x7_,x8_,x9_,x10_};
	for(int i=0; i<elements_.size();++i)
	{
		elements_[i].push_back(temp[i]);
	}
}

PKCompMatrix PKCompMatrix::blankMatrix()
{

    _matrix_logger.Debug( "Creating New Columns" );
    std::vector<PKComplexVar> x_;
    for(int m=0;m<elements_[0].size();++m){x_.push_back(PKComplexVar(0,0));}
    _matrix_logger.Debug( "Creating New Rows" );
    std::vector<std::vector<PKComplexVar> > y_;
    for(int n=0;n<elements_.size();++n){y_.push_back(x_);}
    PKCompMatrix temp(y_);

    return temp;

}

void PKCompMatrix::Print(int precision)
{
	std::cout << "[";
	for(int i=0;i<elements_.size();++i)
	{
		std::cout << "(";
		for(int j=0;j<elements_[0].size();++j)
		{
			std::cout << std::setprecision(precision) << elements_[i][j].returnString();
			if(j+1 < elements_[0].size()){std::cout  << ",";}
			else if(i+1 < elements_.size()){std::cout << ")\n";}
			else{std::cout << ")";}
		}
	}
	std::cout << "]\n";
}
PKCompMatrix PKCompMatrix::operator + (PKCompMatrix param)
{
	_matrix_logger.Info( "Commencing Matrix Addition..." );
	if(param.elements_.size() != elements_.size() && param.elements_[0].size() != elements_[0].size())
	{
		_matrix_logger.Error( "Cannot Add Matrices with Different Dimensions." );
		exit(EXIT_FAILURE);
	}
	_matrix_logger.Debug( "Constructing Addition Template" );
	PKCompMatrix temp = blankMatrix();
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
PKCompMatrix PKCompMatrix::operator - (PKCompMatrix param)
{
	_matrix_logger.Info( "Commencing Matrix Subtraction..." );
	if(param.elements_.size() != elements_.size() && param.elements_[0].size() != elements_[0].size())
	{
		_matrix_logger.Error( "Cannot Subtract Matrices with Different Dimensions - X: %1% vs %2%, Y: %3% vs %4%)", 
				       std::to_string(param.elements_[0].size()), std::to_string(elements_[0].size()),
					std::to_string(param.elements_.size()), std::to_string(elements_.size()) );
		exit(EXIT_FAILURE);
	}
	_matrix_logger.Debug( "Constructing Subtraction Template" );
	PKCompMatrix temp = blankMatrix();
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
PKCompMatrix PKCompMatrix::Transpose()
{
    _matrix_logger.Info( "Calculating Matrix Transpose..." );
    _matrix_logger.Debug( "Constructing Transpose Template" );
    PKCompMatrix temp = blankMatrix();
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
PKCompMatrix PKCompMatrix::operator * (PKCompMatrix param)
{
	_matrix_logger.Info( "Commencing Matrix Multiplication..." );
	_matrix_logger.Debug( "Constructing Multiplication Template" );
	if(param.elements_.size() != elements_[0].size())
	{
		_matrix_logger.Error( "Cannot Multiply Matrices with Dimensions %1% and %2%", 
                                     std::to_string(param.elements_.size()), std::to_string(elements_[0].size()) );
		exit(EXIT_FAILURE);
	}
	PKCompMatrix temp = blankMatrix();
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

PKCompMatrix PKCompMatrix::operator * (PKComplexVar val)
{
    _matrix_logger.Debug( "Multiplying Matrix by PKComplexVar" );
    PKCompMatrix temp = blankMatrix();
    for(int i=0;i<temp.elements_.size();++i)
    {
        for(int j=0;j<temp.elements_[0].size();++j)
        {
		temp.elements_[i][j] = elements_[i][j]*val;
	}
    }
    return temp;
}	

PKCompMatrix PKCompMatrix::operator * (float val)
{
    _matrix_logger.Debug( "Multiplying Matrix by Float" );
    _matrix_logger.Warning( "Converting Float to PKComplexVar(val, 0)" );
    return *this*PKComplexVar(val, 0);
}	
	
PKComplexVar PKCompMatrix::Trace()
{
	_matrix_logger.Info( "Calculating Matrix Trace..." );
	PKComplexVar x_(0,0);

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

bool PKCompMatrix::operator == (PKCompMatrix other)
{
    for(int i=0;i<elements_.size();++i)
    {
        for(int j=0;j<elements_[0].size();++j)
        {
		if(elements_[i][j] != other.elements_[i][j]){return false;}
	}
    }
    return true;
}

bool PKCompMatrix::operator != (PKCompMatrix other)
{
	return !(*this == other);
}	
