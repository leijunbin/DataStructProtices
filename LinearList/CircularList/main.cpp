#include "CircularList.h"
using namespace std;

int main(){
    CircLink<char> test(0);
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
    test.~CircLink();
    return 0;
}
