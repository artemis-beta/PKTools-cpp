#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>

class PKBranch;

class PKLeaf
{
    private:
        void* val;
    public:
        PKBranch* _parent;
        PKLeaf(auto);
        void* getVal();
        PKBranch* getBranch();
        void Print();
};

PKLeaf::PKLeaf(auto i)
{
    auto * val = &i;
}

void* PKLeaf::getVal()
{
    return val;
}

PKBranch* PKLeaf::getBranch()
{
    return _parent;
}

void PKLeaf::Print()
{
    std::cout << getVal() <<std::endl;
}

class PKBranch
{
    private:
        std::vector<PKLeaf> _leaves;
    public:
        std::string branch_name;
        PKLeaf * getEntry(int i);
        void addEntry(auto);
        int getSize();
        void Print();
        PKBranch();
        PKBranch(std::string);
        PKBranch(std::string, std::vector<PKLeaf>);
};

PKBranch::PKBranch(std::string name)
{
    branch_name = name;
}

PKBranch::PKBranch(std::string name, std::vector<PKLeaf> leaves)
{
    branch_name = name;
    _leaves  = leaves;
}

void PKBranch::addEntry(auto entry)
{
    PKLeaf _tmp = PKLeaf(&entry);
    _tmp._parent = this;
    _leaves.push_back(_tmp);
}

int PKBranch::getSize()
{
    return _leaves.size();
}

PKLeaf* PKBranch::getEntry(int i)
{
    return &_leaves[i];
}


void PKBranch::Print()
{
    const std::string branch_out =
        "*********************************************************\n"
        " PKBranch :\t" + branch_name + "\t|\t" + std::to_string(getSize()) + "\n"
        "*********************************************************\n";

    std::cout << branch_out;
}

class PKTree
{
    private:
        std::vector<PKBranch> _branches;
        std::vector<std::string> _branch_names;
    public:
        std::string name;
        void fillBranch(std::string, std::vector<auto>);
        PKBranch* getBranch(std::string);
        PKTree();
        PKTree(std::string name="NewTree");
        void addBranch(std::string);
        PKLeaf * getEntry(std::string, int);
        void Fill();
        void Print();
};

PKTree::PKTree(std::string name)
{
    name = name;
}

void PKTree::addBranch(std::string branch_name)
{
    _branches.push_back(PKBranch(branch_name));
}

PKBranch* PKTree::getBranch(std::string branch_name)
{
    std::vector<std::string>::iterator itr;
    itr = find(_branch_names.begin(), _branch_names.end(), name);

    int pos = itr - _branch_names.begin();
    return &_branches[pos];

}

void PKTree::fillBranch(std::string name, std::vector<auto> elements)
{

    for(int j{0}; j<elements.size(); ++j)
    {
        getBranch(name)->addEntry(elements[j]);
    }
}

void PKTree::Print()
{
    for(int i{0}; i<_branches.size(); ++i)
    {
        _branches[i].Print();
    }
}

PKLeaf * PKTree::getEntry(std::string branch, int i)
{
    return getBranch(name)->getEntry(i);
}
