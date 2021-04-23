#include "SinglyLinkedList.h"

int main(){
    List test;
    test.input();
    test.output();
    cout << test.isEmpty() << endl;
    cout << test.Search(3) << endl;
    char temp = 'd';
    cout << test.Location(temp) << endl;
    temp = 'f';
    test.Insert(4, temp);
    test.Remove(3, temp);
    test.output();
    test.~List();
    return 0;
}
