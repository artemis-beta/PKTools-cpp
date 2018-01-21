#ifndef __PKCONSTMATRIX__
#define __PKCONSTMATRIX__


#include "PKCompMatrix.hxx"
#include "PKLogger.hxx"
#include <stdlib.h>

PKCompMatrix Pauli(int);
PKCompMatrix Dirac(int);
PKCompMatrix alpha(int);
PKCompMatrix beta();
PKCompMatrix g();
PKCompMatrix I(int);

#endif
