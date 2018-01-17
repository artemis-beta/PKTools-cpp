#ifndef __PKTREE_HXX__
#define __PKTREE_HXX__

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

#endif