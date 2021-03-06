#include "DoubleLinkedList.h"
using namespace std;

template <class T>
DblList<T>::DblList(T uniqueVal){
    first = new DblNode<T>(uniqueVal);
    if(first == NULL){
        cout<<"error1"<<endl;
        exit(1);
    }
    first->rLink = first->lLink =first;
}

template<class T>
DblList<T>::~DblList(){
    if(first == NULL)
        return;
    DblNode<T> *current = first->rLink;
    DblNode<T> *next;
    while(current != first){
        next = current-> rLink;
        delete current;
        current = next;
    }
    delete first;
    first = NULL;
}

template <class T>
int DblList<T>::Length()const{
    DblNode<T> *current = first->rLink;
    int count=0;
    while(current != first){
        current = current->rLink;
        count++;
    }
    return count;
}

template <class T>
int DblList<T>::Search(const T &x){
    int count = 1;
    DblNode<T> *current = first->rLink;
    while(current != first && current->data != x){
        current = current->rLink;
        count++;
    }
    if(current != first)
        return count;
    else
        return NULL;
}

template <class T>
DblNode<T>* DblList<T>::Locate(int i, int d){
    if(first->rLink == first || i==0)
        return first;
    DblNode<T> *current;
    if(d==0)
        current = first->lLink;
    else
        current = first->rLink;
    for(int j = 1; j < i; j++)
        if(current == first)
            break;
        else if(d == 0)
            current = current->lLink;
        else
            current = current->rLink;
        if(current != first)
            return current;
        else
            return NULL;
}

template <class T>
bool DblList<T>::Insert(int i, const T &x, int d){
    DblNode<T> *current = Locate(i, d);
    if(current == NULL)
        return false;
    DblNode<T> *newNode = new DblNode<T>(x);
    if(newNode == NULL){
        cout<<"error1"<<endl;
    }
    if(d==0){
        newNode->lLink = current->lLink;
        current->lLink = newNode;
        newNode->lLink->rLink = newNode;
        newNode->rLink = current;
    }
    else{
        newNode->rLink = current->rLink;
        current->rLink = newNode;
        newNode->rLink->lLink = newNode;
        newNode->lLink = current;
    }
    return true;
}

template <class T>
bool DblList<T>::Remove(int i, T &x, int d){
    DblNode<T> *current = Locate(i, d);
    if(current == NULL)
        return false;
    current->rLink->lLink = current->lLink;
    current->lLink->rLink = current->rLink;
    x = current->data;
    delete current;
    return true;
}

template <class T>
void DblList<T>::output(){
    DblNode<T> *current = first->rLink;
    while(current != first){
        cout<<current->data<<" ";
        current = current->rLink;
    }
    cout<<endl;
}
