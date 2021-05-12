#include "CircularList.h"
using namespace std;

template <class T>
CircLink<T>::CircLink(const T &x){
    first = new CircLinkNode<T>(x);
    first->link = first;
}

template <class T>
CircLink<T>::~CircLink(){
    if(first == NULL)
        return;
    CircLinkNode<T> *current = first->link;
    CircLinkNode<T> *tel;
    while(current != first){
        tel = current;
        current = current->link;
        delete tel;
    }
    delete first;
    first = NULL;
}

template <class T>
T CircLink<T>::Search(int i){
    CircLinkNode<T> *current = first;
    for(int k = 1; current != first && k < i; k++){
        current = current -> link;
    }
    if(current == first || current -> link == first)
        return '\0';
    else{
        return current -> data;
    }
}

template <class T>
int CircLink<T>::Location(T &x){
    CircLinkNode<T> *current = first;
    int res = 1;
    while(current != first){
        if(current -> data == x){
            return res;
        }
        else{
            current = current -> link;
            res++;
        }
    }
    if(current == first)
        return -1;
}

template <class T>
bool CircLink<T>::Insert(int i, T &x){
    CircLinkNode<T> *current = first->link;
    for(int k = 1; k < i; k++){
        current = current->link;
    }
    CircLinkNode<T> *newNode = new CircLinkNode<T>(x);
    if(newNode == NULL){
        cout << "Memory allocation error." << endl;
        exit(1);
    }
    newNode -> link = current -> link;
    current -> link = newNode;
    return true;
}

template <class T>
bool CircLink<T>::Remove(int i, T &x){
    CircLinkNode<T> *del,*current;
    if(i <= 1){
        del = first;
        first = first -> link;
    }
    else{
        current = first->link;
        for(int k = 1; k < i - 1; k++){
            if(current == first)
                break;
            else
                current = current -> link;
        }
        if(current == first || current -> link == first){
            cout << "Please check the number you input."<<endl;
            return false;
        }
        del = current -> link;
        current -> link = del -> link;
    }
    x = del -> data;
    delete del;
    return true;
}

template <class T>
void CircLink<T>::input(){
    int maxSize;
    cout << "Begin build sequential list, please input number in this sequential list:";
    cin >> maxSize;
    for(int i = 0; i < maxSize; i++){
        T data;
        cin >> data;
        Insert(i, data);
    }
}

template <class T>
void CircLink<T>::output(){
    int res = 0;
    CircLinkNode<T> *current = first->link;
    while(current != first){
        cout << "#" << res + 1 << ":" << current -> data << endl;
        current = current -> link;
        res++;
    }
    cout << "Sequential list the last location:" << res << endl;
}

