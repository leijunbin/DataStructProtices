#include "SequentialList.h"

template <class T>
void SequentialList<T>::reSize(int newSize){
    if(newSize <= 0 && newSize < last + 1){
        std::cerr << "Please check the newSzie you input." << std::endl;
    }
    if(newSize != maxSize){
        T *newarray = new T[newSize];
        if(newarray == NULL){
            std::cerr << "Memory allocation error." << std::endl;
            exit(1);
        }
        int n = last + 1;
        T *srcptr = data;
        T *destptr = newarray;
        while(n--)
            *destptr++ = *srcptr++;
        delete []data;
        data = newarray;
        maxSize = newSize;
    }
}

template <class T>
SequentialList<T>::SequentialList(int sz){
    if(sz > 0){
        maxSize = sz;
        last = -1;
        data = new T[maxSize];
        if(data == NULL){
            std::cerr << "Memory allocation error." << std::endl;
            exit(1);
        }
    }
}

template <class T>
SequentialList<T>::SequentialList(SequentialList<T> &L){
    maxSize = L.size();
    last = L.Length() - 1;
    T value;
    data = new T[maxSize];
    if(data == NULL){
        std::cerr << "" << std::endl;
        exit(1);
    }
    for(int i = 1; i <= last + 1; i++){
        L.getData(i, value);
        data[i-1]=value;
    }
}

template <class T>
SequentialList<T>::~SequentialList(){
    delete []data;
    maxSize = 0;
    last = -1;
}

template <class T>
int SequentialList<T>::size() const{
    return maxSize;
}

template <class T>
int SequentialList<T>::Length() const{
    return last + 1;
}

template <class T>
int SequentialList<T>::Search(T &x) const{
    for(int i = 0; i <= last; i++)
        if(data[i] == x)
            return i+1;
    return 0;
}

template <class T>
int SequentialList<T>::Locate(int i) const{
    if(i >= 1 && i <= last + 1){
        return i;
    }
    else
    return 0;
}

template <class T>
bool SequentialList<T>::getData(int i, T &x) const{
    if(i > 0 && i <= last + 1){
        x = data[i - 1];
        return true;
    }
    else
        return false;
}

template <class T>
void SequentialList<T>::setData(int i, T &x){
    if(i > 0 && i <= last + 1)
        data[i - 1] = x;
}

template <class T>
bool SequentialList<T>::Insert(int i, T &x){
    if(last == maxSize - 1)
        return false;
    if(i < 0 || i > last + 1)
        return false;
    for(int j = last; j >= i; j--){
        data[j + 1] = data[j];
    }
    data[i] = x;
    last++;
    return true;
}

template <class T>
bool SequentialList<T>::Remove(int i, T &x){
    if(last == -1)
        return false;
    if(i < 1 || i > last + 1)
        return false;
    x = data[i-1];
    for(int j = i; j <= last; j++)
        data[j - 1] = data[j];
    last--;
    return true;
}

template <class T>
bool SequentialList<T>::IsEmpty(){
    return (last == -1) ? true : false;
}

template <class T>
bool SequentialList<T>::IsFull(){
    return (last == maxSize - 1) ? true : false;
}

template <class T>
void SequentialList<T>::input(){
    std::cout << "Begin build sequential list, please input number in this sequential list:";
    while(1){
        int tlast;
        std::cin >> tlast;
        last = tlast - 1;
        if(last <= maxSize - 1)
            break;
        std::cout << "Please check the number you input:";
    }
    for(int i = 0; i <= last; i++){
        std::cin >> data[i];
        std::cout << i + 1 << std::endl;
    }
}

template <class T>
void SequentialList<T>::output(){
    std::cout << "Sequential list the last location:" << last << std::endl;
    for(int i = 0; i <= last; i++){
        std::cout << "#" << i + 1 << ":" << data[i] << std::endl;
    }
}
