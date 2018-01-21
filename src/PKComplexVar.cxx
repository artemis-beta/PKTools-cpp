#include "PKComplexVar.hxx"

PKComplexVar::PKComplexVar(float re, float im)
{
	_real = re;
	_imagin = im;
	_modulus = pow(_real*_real + _imagin*_imagin, 0.5);

	if(_real != 0){	_arg = tan(_imagin/_real);}
	else{_arg = 0;}
}

float PKComplexVar::getRe()
{
	return _real;
}

float PKComplexVar::getIm()
{
	return _imagin;
}

float PKComplexVar::getMod()
{
	return _modulus;
}

float PKComplexVar::getArg()
{
	return _arg;
}

void PKComplexVar::_setReal(float val)
{
	_real = val;
}

void PKComplexVar::_setImag(float val)
{
	_imagin = val;
}

std::string PKComplexVar::returnString(int opt)
{
	std::string outstring = "";
	switch(opt)
	{
		case 0:
			if(_real != 0 || _imagin == 0)
			{
				outstring += std::to_string(_real);
			}
			if(_imagin != 0)
			{	
				if(_imagin > 0){outstring += "+";}
				outstring += std::to_string(_imagin) + "i";
			}
			break;
		case 1:
			if(_imagin = 0){outstring = "1";}
			else
			{
				outstring += std::to_string(_modulus) + "*exp(";
				if(_arg < 0){outstring += "-";}
				outstring += std::to_string(_arg) + "i";
			}
			break;
		
		case 2:
			if(_imagin == 0){outstring = "1";}
			else
			{
				outstring += std::to_string(_real) + "*cos(" + std::to_string(_arg) + ")";
				if(_imagin > 0){outstring += "+";}
				outstring += std::to_string(_imagin) + "i*sin(" + std::to_string(_arg) + ")";
			}
			break;
		default:
			std::cout << "ERROR: Invalid integer argument for PKComplexVar::Print(int) options are 0, 1, 2" << std::endl;
			exit(EXIT_FAILURE);
	}
	return outstring;
}

void PKComplexVar::Print(int opt, int precision)
{
	std::cout << std::setprecision(precision) << returnString(opt) << std::endl;
}

PKComplexVar PKComplexVar::operator + (PKComplexVar other)
{
	PKComplexVar temp = PKComplexVar(0,0);
	temp._setReal(_real + other.getRe());
	temp._setImag(_imagin + other.getIm());
	return temp;
}

PKComplexVar PKComplexVar::operator - (PKComplexVar other)
{	
	PKComplexVar temp = PKComplexVar(0,0);
	temp._setReal(_real - other.getRe());
	temp._setImag(_imagin - other.getIm());
	return temp;
}

PKComplexVar PKComplexVar::operator * (PKComplexVar other)
{
	PKComplexVar temp = PKComplexVar(0,0);
	temp._setReal(_real*other.getRe()-_imagin*other.getIm());
	temp._setImag(_real*other.getIm() + _imagin*other.getRe());
	return temp;
}

PKComplexVar PKComplexVar::operator * (int other)
{
	PKComplexVar temp = PKComplexVar(0,0);
	if(_real != 0){temp._setReal(_real*other);}
	if(_imagin != 0){temp._setImag(_imagin*other);}
	return temp;
}

PKComplexVar PKComplexVar::operator * (float other)
{
	PKComplexVar temp = PKComplexVar(0,0);
	if(_real != 0){temp._setReal(_real*other);}
	if(_imagin != 0){temp._setImag(_imagin*other);}
	return temp;
}

PKComplexVar PKComplexVar::operator * (double other)
{
	PKComplexVar temp = PKComplexVar(0,0);
	if(_real != 0){temp._setReal(_real*other);}
	if(_imagin != 0){temp._setImag(_imagin*other);}
	return temp;
}

PKComplexVar PKComplexVar::operator / (PKComplexVar other)
{
	PKComplexVar temp = PKComplexVar(0,0);
	_modulus = _modulus/other.getMod();
	float arg_temp = _arg - other.getArg();
	temp._setReal(_modulus/pow(1+atan(arg_temp), 0.5));
	temp._setImag(_modulus*atan(arg_temp)/pow(1+pow(atan(arg_temp),2),0.5));
	return temp;
}

PKComplexVar PKComplexVar::operator / (int other)
{
	PKComplexVar temp = PKComplexVar(0,0);
	if(_real != 0){temp._setReal(_real/other);}
	if(_imagin != 0){temp._setImag(_imagin/other);}
	return temp;
}

PKComplexVar PKComplexVar::operator / (float other)
{
	PKComplexVar temp = PKComplexVar(0,0);
	if(_real != 0){temp._setReal(_real/other);}
	if(_imagin != 0){temp._setImag(_imagin/other);}
	return temp;
}

PKComplexVar PKComplexVar::operator / (double other)
{
	PKComplexVar temp = PKComplexVar(0,0);
	if(_real != 0){temp._setReal(_real/other);}
	if(_imagin != 0){temp._setImag(_imagin/other);}
	return temp;
}

PKComplexVar operator * (int other, PKComplexVar pkv)
{
	PKComplexVar temp = PKComplexVar(0,0);
	if(pkv.getRe() != 0){temp._setReal(pkv.getRe()*other);}
	if(pkv.getIm() != 0){temp._setImag(pkv.getIm()*other);}
	return temp;
}

PKComplexVar operator * (float other, PKComplexVar pkv)
{
	PKComplexVar temp = PKComplexVar(0,0);
	if(pkv.getRe() != 0){temp._setReal(pkv.getRe()*other);}
	if(pkv.getIm() != 0){temp._setImag(pkv.getIm()*other);}
	return temp;
}

PKComplexVar operator * (double other, PKComplexVar pkv)
{
	PKComplexVar temp = PKComplexVar(0,0);
	if(pkv.getRe() != 0){temp._setReal(pkv.getRe()*other);}
	if(pkv.getIm() != 0){temp._setImag(pkv.getIm()*other);}
	return temp;
}

bool PKComplexVar::operator == (PKComplexVar other)
{
	if(this->getRe() != other.getRe()){return false;}
	if(this->getIm() != other.getIm()){return false;}
	return true;
}

bool PKComplexVar::operator != (PKComplexVar other)
{
	return !(*this == other);
}
