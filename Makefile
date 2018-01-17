CXXFILES = src/PKMatrix.cxx src/PKLogger.cxx src/PKGlobalDef.cxx src/PKVar.cxx src/PKLorentzVector.cxx src/PKComplexVar.cxx
PROGRAM = Matrix_Example
PROGRAM_CXX = $(PROGRAM:%=examples/%.cxx)
PROGRAM_OBJ = $(PROGRAM:%=obj/%.o)
CXX = g++
CXXFLAGS = -Wall -std=c++14 -I src/
OBJECTS=$(patsubst src/%.cxx, obj/%.o, $(CXXFILES))

all: $(OBJECTS) $(PROGRAM_OBJ)
	$(CXX) -o bin/$(PROGRAM) $(OBJECTS) $(PROGRAM_OBJ)

$(OBJECTS): $(CXXFILES)
	$(CXX) $(CXXFLAGS) -c $(CXXFILES)
	mv *.o obj/

$(PROGRAM_OBJ): $(PROGRAM_CXX)
	$(CXX) $(CXXFLAGS) -c $(PROGRAM_CXX)
	mv *.o obj/

clean:
	rm bin/$(PROGRAM) obj/*.o
