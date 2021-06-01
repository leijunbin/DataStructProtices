#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e5+100;
char t[maxn];
char example[5]="abcd";

int main(){
    cin>>t;
    int n=strlen(t);
    int res=0,i;
    for(i=0;i<n;i++){
        if(t[i]==example[0]){
            int j=0;
            for(j=0;j<4;j++){
                if(t[i+j]!=example[j]){
                    break;
                }
                if(j==3){
                    res+=4;
                    j=0,i+=4;
                }
            }
            if(res!=0)
                break;
        }
    }
    cout<<i-res+1<<" "<<res<<endl;
    return 0;
}
