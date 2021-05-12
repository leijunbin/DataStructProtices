#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <iostream>

template <class T>
struct CircLinkNode{
    T data;
    CircLinkNode<T> *link;
    CircLinkNode(CircLinkNode<T> *next = NULL)
        :link(next){}
    CircLinkNode(T d, CircLinkNode<T> *next = NULL)
        :data(d), link(next){}
};

template <class T>
class CircLink{
    public:
        CircLink(const T &x);
        ~CircLink();
        T Search(int i);
        int Location(T &x);
        bool Insert(int i, T &x);
        bool Remove(int i, T &x);
        bool isEmpty() const{
            return first->link == first;
        }
        void input();
        void output();
    private:
        CircLinkNode<T> *first = NULL;
};

#include "CircularList.tpp"

#endif // CIRCULARLIST_H
