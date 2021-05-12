#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>

template <class T>
struct DblNode{
    T data;
    DblNode<T> *lLink, *rLink;
    DblNode(DblNode<T> *left = NULL, DblNode<T> *right = NULL)
        :lLink(left), rLink(right){}
    DblNode(T value, DblNode<T> *left = NULL, DblNode<T> *right = NULL)
        :data(value), lLink(left), rLink(right){}
};

template <class T>
class DblList{
    public:
        DblList(T uniqueVal);
        ~DblList();
        int Length() const;
        bool IsEmpty(){
            return first->rLink == first;
        }
        DblNode<T> *getHead() const{
            return first;
        }
        void setHead(DblNode<T> *ptr){
            first = ptr;
        }
        int Search(const T& x);
        DblNode<T> *Locate(int i,int d);
        bool Insert(int i, const T &x, int d);
        bool Remove(int i, T &x, int d);
        void output();
    private:
        DblNode<T> *first;
};

#include "DoubleLinkedList.tpp"

#endif
