#include<iostream>
using namespace std;

int a[10]={1,2,3,4,5,6,7,8,9,10};

int BinarySearch(int n){
    int i=0,j=9;
    while(i<=j){
        int mid=(i+j)/2;
        if(a[mid]<n){
            i=mid;
        }
        else if(a[mid]>n){
            j=mid;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    cout<<BinarySearch(5)+1<<endl;
    return 0;
}
