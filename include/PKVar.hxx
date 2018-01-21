#ifndef __PKVAR__
#define __PKVAR__

class PKVar {

	private:
		float value_;
		float error_;
	public:
		float getVal();
		float getError();
		void Print();
		PKVar(float value, float error);
		PKVar();
		PKVar Power(float x);
		PKVar Sqrt();
		PKVar operator + (PKVar);
		PKVar operator - (PKVar);
		PKVar operator * (PKVar);
		PKVar operator / (PKVar);
};
#endif
