#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <stdlib.h>
using namespace std;
typedef char ElementData;

struct LinkNode{
    ElementData data;
    LinkNode *link;
    LinkNode(ElementData tdata){
        data = tdata;
    }
};

class List{
    public:
        List();
        ~List();
        ElementData Search(int i);
        int Location(ElementData &x);
        bool Insert(int i, ElementData &x);
        bool Remove(int i, ElementData &x);
        bool isEmpty() const;
        void input();
        void output();
    private:
        LinkNode *first = NULL;
};

#endif // SINGLYLINKEDLIST_H
