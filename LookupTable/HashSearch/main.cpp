#include<iostream>
#define MaxSize 100
#define NULLKEY -1
#define DELKEY -2
using namespace std;

typedef int KeyType;
typedef char* InfoType;

typedef struct{
    KeyType key;
    InfoType data;
    int count;
} HashData;

typedef HashData HashTable[MaxSize];
int n1=0;

void InsertHT(HashTable ha,int &n,KeyType k,int p,int m){
    int i,adr;
    adr=k%p;
    if(ha[adr].key==NULLKEY||ha[adr].key==DELKEY){
        ha[adr].key=k;
        ha[adr].count=1;
    }
    else{
        i=1;
        do{
            adr=(adr+1)%m;
            i++;
        }while(ha[adr].key!=NULLKEY&&ha[adr].key==DELKEY);

        ha[adr].key=k;
        ha[adr].count=i;
    }
    n++;
}

void CreateHT(HashTable ha,KeyType x[],int n,int m,int p){
    int i;
    for(i=0;i<m;i++){
        ha[i].key=NULLKEY;
        ha[i].count=0;
    }
    for(int i=0;i<n;i++){
        InsertHT(ha,n1,x[i],p,m);
    }
}

int SearchHT(HashTable ha,int p,KeyType k,int m){
    int i=0,adr;
    adr=k%p;

    while(ha[adr].key!=NULLKEY&&ha[adr].key!=k){
        i++;
        adr=(adr+1)%m;
    }

    if(ha[adr].key==k)
        return adr;
    else
        return -1;
}

int DeleteHT(HashTable ha,int p,KeyType k,int &n,int m){
    int adr;
    adr=SearchHT(ha,p,k,m);
    if(adr!=-1){
        ha[adr].key=DELKEY;
        n--;
        return 1;
    }
    else{
        return 0;
    }
}

KeyType example[12]={16,74,60,43,54,90,46,31,29,88,77};

int main(){
    int p;
    cin>>p;
    HashTable test;
    CreateHT(test,example,12,12,p);
    cout<<SearchHT(test,p,29,12)<<endl;
    DeleteHT(test,p,77,n1,12);
    cout<<SearchHT(test,p,77,12)<<endl;
    InsertHT(test,n1,77,p,12);
    cout<<SearchHT(test,p,77,12)<<endl;
    return 0;
}
