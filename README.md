# 2016 JCNK Hackathon C++ Club
Just a place for us to bolt together some code as part of training in our spare time.
## PKTriangle
A simple class which can be given either Side-Side-Angle (`"SSA"`) or Angle-Angle-Side (`"AAS"`) value combinations, the other values are then calculated to give a triangle:
```
PKTriangle(par1,par2,par3,"AAS")
```
To compile the included example, simply run within the `examples` folder:
```
g++ PKTriangle_Example.cpp PKTriangle.cpp -o PKTriangleExample -I ../source/
```
this will build an executable `PKTriangleExample` which can be run from the command line.

## PKVariables and PKLorentz Vector
Two classes have been added which allow the inclusion of errors alongside variables. The Lorentz Vector class `PKLorentzVector` allows construction of a four vector using four `PKVars` with variables and their respective errors. Two examples have been included to illustrate:
```
g++ AddPKVars.cpp -o AddPKVars -I ../source/
```
```
g++ LorentzVectors.cpp -o LorentzVectors -I ../source/
```
compiling will produce the two excutables `AddPKVars` and `LorentzVectors` within the `examples` folder.
