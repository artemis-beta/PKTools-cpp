# Physics Kit
A set of classes for use in physical systems, this package is experimental! **Requires**: `boost-1.61` (likely to work in other versions but has been tested with this build).
## PKTriangle
A simple class which can be given either Side-Side-Angle (`"SSA"`) or Angle-Angle-Side (`"AAS"`) value combinations, the other values are then calculated to give a triangle:
```
PKTriangle(par1,par2,par3,"AAS")
```

## PKVariables and PKLorentz Vector
Two classes have been added which allow the inclusion of errors alongside variables. The Lorentz Vector class `PKLorentzVector` allows construction of a four vector using four `PKVars` with variables and their respective errors. Two examples have been included to illustrate:
```
g++ AddPKVars.cpp -o AddPKVars -I ../source/
```
```
g++ LorentzVectors.cpp -o LorentzVectors -I ../source/
```
compiling will produce the two excutables `AddPKVars` and `LorentzVectors` within the `examples` folder.

## PKMatrix
A class that allows the construction of up to a 10x10 matrix using `PKVar` variables. Construction is through either manually creating a `std::vector<std::vector<PKVar> >`, a vector of rows, the length then being the number of columns, or by creating an empty instance:
```
PKMatrix matrix;
matrix.addRow(PKVar(1,0),PKVar(0,0));
matrix.addRow(PKVar(0,0),PKVar(1,0));
```
this example being one of the Pauli matrices.

## Compiling the Examples
We recommend you compile the examples by running the included bash script:
```
bash ./make.sh
```
The script assumes you have a local copy of the BOOST library installed in the directory `/usr/include`. You can edit the script to alter the location if necessary. The executables for the examples are placed in the `bin` folder.
