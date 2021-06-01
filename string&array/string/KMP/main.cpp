#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int nexts[maxn]={0};
char t[6]="aabbd";
char s[maxn];

void getnextn(int length){
    nexts[0]=-1;
    int i=0,j=-1;
    while(i<length){
        if(j==-1||t[i]==t[j])
            nexts[++i]=++j;
        else
            j=nexts[j];
    }
}

int kmp(int n1,int n2){
    int i=0,j=0,res=0;
    while(i<n1&&j<n2){
        if(j==-1||s[i]==t[j]){
            i++,j++;
        }
        else{
            j=nexts[j];
        }
        if(j>=n2){
            j=nexts[j-1];
            res++;
        }
    }
    return res;
}

int main(){
    cin>>s;
    getnextn(5);
    int n=kmp(strlen(s),5);
    cout<<n<<endl;
    return 0;
}
