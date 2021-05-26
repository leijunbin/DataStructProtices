#include "buildtree.h"
#include "calculate.h"
#include "bigint.h"
using namespace std;

int count = 0;
point tmp[100];

void cyanPrint(string str){
    cout << str;
}

int main()
{

    string e_str;
    cin >> e_str;

    buildTree a;
    a.buildTrees(e_str);

    BigInt result(0);
    BigInt rslt(0);

    cout << "You are Calculating: " << endl;
    cyanPrint(e_str);
    cout << endl;

    int count = a.postorder(tmp) + 1;
    calculateBehind b(tmp, count);
    result = b.calculate();
    cout << result << endl;

    system("pause");

    return 0;
}
