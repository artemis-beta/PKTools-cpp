mkdir -p bin
mkdir -p obj

export BOOSTINCLUDE=/usr/include

make PROGRAM=Matrix_Example FMTLIB=/usr/local/include/ 
make PROGRAM=CompMatrix_Example FMTLIB=/usr/local/include/ 
make PROGRAM=PKTriangle_Example BOOSTINCLUDE=$BOOSTINCLUDE
make PROGRAM=AddPKVars FMTLIB=/usr/local/include/
make PROGRAM=AddPKComplexVars FMTLIB=/usr/local/include/
make PROGRAM=LorentzVectors FMTLIB=/usr/local/include/
make PROGRAM=PKRectangle_Example FMTLIB=/usr/local/include/
make PROGRAM=GammaMatrices FMTLIB=/usr/local/include/
