#include "SequentialList.h"
using namespace std;

int main(){
    int maxSizes = 100;
    SequentialList<char> test(100);
    test.input();
    test.output();
    cout << test.Length() << endl;
    cout << test.IsEmpty() << endl;
    char temp;
    test.getData(3, temp);
    cout << temp << endl;
    temp = 'd';
    cout << test.Search(temp) << endl;
    temp = 'f';
    test.Insert(4, temp);
    test.Remove(3, temp);
    test.output();
    test.~SequentialList();
    return 0;
}
