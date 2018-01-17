#include <iostream>
#include "PKTree.hxx"
#include <vector>

int main(void)
{
	std::vector<double> x;
	for(int i{0}; i<10; ++i){x.push_back(i);}
	PKTree * tree = new PKTree("test_tree");
	tree->addBranch("testBranch");
	tree->fillBranch("testBranch", x);
    	PKBranch* branch = tree->getBranch("testBranch");
    	tree->Print();
    	(*tree->getEntry("testBranch", 6)).Print();
}
