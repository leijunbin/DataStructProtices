#include<iostream>
using namespace std;

void print(int *a,int n){
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void shellSort(int *a,int n){
    int dk=n/2;
    while(dk>=1){
        for(int i=dk;i<=n;i++){
            int j=i-dk;
            int key=a[i];
            while(j>0&&key<a[j]){
                a[j+dk]=a[j];
                j-=dk;
            }
            a[j+dk]=key;
            print(a,n);
        }
        dk/=2;
    }
}

int a[11]={0,9,8,7,6,5,4,3,2,1,0};

int main(){
    shellSort(a,10);
    return 0;
}
