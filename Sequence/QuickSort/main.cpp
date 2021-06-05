#include<iostream>
using namespace std;

int n=10;
void print(int *a,int n){
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void QuickSort(int *a,int low,int high){
    if(high<=low)
        return;
    int i=low;
    int j=high+1;
    int key=a[low];
    while(1){
        while(a[++i]<key){
            if(i==high)
                break;
        }
        while(a[--j]>key){
            if(j==low)
                break;
        }
        if(i>=j)
            break;
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    int temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    print(a,n);
    QuickSort(a,low,j-1);
    QuickSort(a,j+1,high);
}

int a[11]={0,6,8,7,9,0,1,3,2,4,5};

int main(){
    QuickSort(a,1,10);
    return 0;
}
