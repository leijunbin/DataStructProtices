#include "DoubleLinkedList.h"


int main(){
    DblList<char> h(0);
    h.Insert(0, 'a', 1);
    h.Insert(1, 'b', 1);
    h.Insert(2, 'c', 1);
    h.Insert(3, 'd', 1);
    h.Insert(4, 'e', 1);
    h.output();
    cout<<h.IsEmpty()<<endl;
    cout<<(h.Locate(3, 1)->data)<<endl;
    char temp = 'd';
    cout<<h.Search(temp)<<endl;
    temp = 'f';
    h.Insert(4, temp, 1);
    h.Remove(3, temp, 1);
    h.output();
    h.~DblList();
    return 0;
}
