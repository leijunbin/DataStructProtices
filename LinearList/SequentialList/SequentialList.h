#ifndef SEQUENTIALLIST_H
#define SEQUENTIALLIST_H

#include<iostream>
#include<stdlib.h>

const int defaultSize = 100;

template <class T>
class SequentialList{
    public:
        SequentialList(int sz = defaultSize);
        SequentialList(SequentialList<T> &L);
        ~SequentialList();
        int size() const;
        int Length() const;
        int Search(T &x) const;
        int Locate(int i) const;
        bool getData(int i, T &x) const;
        void setData(int i, T &x);
        bool Insert(int i, T &x);
        bool Remove(int i, T &x);
        bool IsEmpty();
        bool IsFull();

        void input();
        void output();
        SequentialList<T> operator=(SequentialList<T> &L);

    private:
        T *data;
        int maxSize;
        int last;
        void reSize(int newSize);
};

#include "SequentialList.tpp"

#endif // SEQUENTIALLIST_H
