CXXFILES = src/PKMatrix.cxx src/PKLogger.cxx src/PKGlobalDef.cxx src/PKVar.cxx src/PKTree.cxx src/PKLorentzVector.cxx src/PKComplexVar.cxx src/PKTriangle.cxx src/PKRectangle.cxx
PROGRAM_CXX = $(PROGRAM:%=examples/%.cxx)
PROGRAM_OBJ = $(PROGRAM:%=obj/%.o)
CXX = g++
CXXFLAGS = -Wall -std=c++14 -I src/
OBJECTS=$(patsubst src/%.cxx, obj/%.o, $(CXXFILES))

$(PROGRAM): $(PROGRAM_OBJ) $(OBJECTS)
	$(CXX) -o bin/$(PROGRAM) $(PROGRAM_OBJ) $(OBJECTS)

$(OBJECTS): $(CXXFILES)
	$(CXX) $(CXXFLAGS) -c $(CXXFILES)
	mv *.o obj/

$(PROGRAM_OBJ): $(PROGRAM_CXX)
	$(CXX) $(CXXFLAGS) -c $(PROGRAM_CXX)
	mv *.o obj/

clean:
	rm bin/* obj/*.o
