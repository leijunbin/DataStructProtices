#include<iostream>
using namespace std;

void print(int *a,int n){
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void InsertionSort(int *a,int n){
    for(int i=2;i<=n;i++){
        int key=a[i];
        int j=i-1;
        while(j>0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        print(a,n);
    }
}

int a[11]={0,9,8,7,6,5,4,3,2,1,0};

int main(){
    InsertionSort(a,10);
    return 0;
}
