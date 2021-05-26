#include<iostream>
using namespace std;
typedef int Data;
const int maxn=1e5+100;
int behind=-1;

struct node{
    Data data;
    node *next;
    node():next(NULL){}
};
node* start;

node* stack[maxn];

void init(){
    start=new node;
}

void add(Data t){
    node *newNode=new node;
    newNode->data=t;
    node* current=start;
    while(!(current->next==NULL)){
        current=current->next;
    }
    current->next=newNode;
}

node* reverseList(){
    node* current=start;
    while(!(current->next==NULL)){
        current=current->next;
        stack[++behind]=current;
    }
    current=start;
    while(behind>=0){
        current->next=stack[behind--];
        current=current->next;
    }
    current->next=NULL;
    return start;
}

void addN(){
    int n;
    cin>>n;
    while(n--){
        Data t;
        cin>>t;
        add(t);
    }
}

void printf(node* p){
    while(!(p->next==NULL)){
        p=p->next;
        cout<<p->data<<" ";
    }
    cout<<endl;
}

void deletes(node *p){
    node *current=p;
    while(!(current->next==NULL)){
        node *del=current;
        current=current->next;
        delete del;
    }
}

void solve1(){
    init();
    addN();
    node *res=reverseList();
    printf(res);
    deletes(res);
}

int maxValue(int *a,int k){
    if(k==1)
        return a[0];
    else{
        int temp=maxValue(a,k-1);
        return (temp>a[k-1]?temp:a[k-1]);
    }
}

int sum(int* a,int k){
    if(k==1)
        return a[0];
    else
        return sum(a,k-1)+a[k-1];
}

float average(int *a,int k){
    if(k==1)
        return a[0];
    else
        return ((k-1)*average(a,k-1)+a[k-1])/k;
}

void solve2(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<maxValue(a,n)<<" "<<sum(a,n)<<" "<<average(a,n)<<endl;
}

int vis[maxn]={0};
int res[maxn]={0};
void dfs(int* a,int dp,int n){
    if(dp==n){
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                res[dp]=i;
                for(int i=1;i<=n;i++){
                    cout<<a[res[i]]<<" ";
                }
                cout<<endl;
                return;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            vis[i]=1;
            res[dp]=i;
            dfs(a,dp+1,n);
            vis[i]=0;
        }
    }
}

void solve3(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    dfs(a,1,n);
}

int main(){
    solve1();
    solve2();
    solve3();
    return 0;
}
