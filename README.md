# 2016 JCNK Hackathon C++ Club
Just a place for us to bolt together some code as part of training in our spare time.
## PKTriangle
A simple class which can be given either Side-Side-Angle (`"SSA"`) or Angle-Angle-Side (`"AAS"`) value combinations, the other values are then calculated to give a triangle:
```
PKTriangle(par1,par2,par3,"AAS")
```
To compile the included example, simply run:
```
g++ PKTriangle_Example.cpp PKTriangle.cpp -o PKTriangleExample -I .
```
this will build an executable `PKTriangleExample` which can be run from the command line.
