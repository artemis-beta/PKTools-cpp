#ifndef __PKVAR__
#define __PKVAR__

class PKVar {

	private:
		double value_;
		double error_;
	public:
		double GetVal();
		double GetError();
		void Print();
		PKVar(double value, double error);
		PKVar();
		PKVar Power(double x);
		PKVar Sqrt();
		PKVar operator + (PKVar);
		PKVar operator - (PKVar);
		PKVar operator * (PKVar);
		PKVar operator / (PKVar);
};
#endif
