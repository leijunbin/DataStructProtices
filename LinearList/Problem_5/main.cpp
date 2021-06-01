#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e5+100;
int vis[maxn]={0};

int main(){
    memset(vis,0,sizeof(vis));
    int n,m;
    cout<<"请分别输入总数与标记数：";
    cin>>n>>m;
    int puts=0;
    int count=1;
    int number=0;
    cout<<"结果为：";
    while(puts<n){
        if(count>n){
            count=count%n;
        }
        if(vis[count]==0&&number<m){
            number++;
        }
        if(vis[count]==0&&number==m){
            vis[count]=1;
            number=0;
            cout<<count<<" ";
            puts++;
        }
        count=count+1;
    }
    return 0;
}

