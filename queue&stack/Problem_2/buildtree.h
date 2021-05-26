#ifndef BUILDTREE_H
#define BUILDTREE_H

#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include "bigint.h"
using namespace std;

struct point
{
    BigInt a;
    char b = 0;
};

struct expressTree
{
    point m;
    expressTree *lchild = NULL;
    expressTree *rchild = NULL;
};

class buildTree
{
public:
    buildTree();
    ~buildTree();
    void buildTrees(string str);
    void setroot(expressTree *k);
    int preorder(point *b);
    int postorder(point *b);

private:
    expressTree *root;
    bool isnumber(char c);
    bool isope(char c);
    int opelevel(char c);
};


#endif // BUILDTREE_H
