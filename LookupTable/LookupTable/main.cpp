#include<iostream>
using namespace std;

int a[10]={3,6,2,10,1,8,5,7,4,9};

int findNumber(int n){
    for(int i=0;i<10;i++){
        if(a[i]==n)
            return i;
    }
    return -1;
}

int main(){
    cout<<findNumber(5)+1<<endl;
    return 0;
}
