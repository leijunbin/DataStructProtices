#include<iostream>
#include<iomanip>
#include<stack>
#include<cstring>
#include<map>
using namespace std;
const int maxn=100;
const int inf=0x3f3f3f3f;
const int maxnEdge=(maxn<<1)-1;

int GraphAdjacencyMatrix[maxn][maxn];
int res1[maxn][maxn];
int vis[maxn]={0};

int res2[maxn]={0};
int res2count=1;

int head[maxn];
struct edge{
    int to,next;
    int w;
}edge[maxnEdge];
int count=0;

void init(){
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            GraphAdjacencyMatrix[i][j]=inf;
            res1[i][j]=inf;
        }
    }
    for(int i=0;i<maxn;i++){
        head[i]=-1;
    }
    for(int i=1;i<maxn;i++){
        GraphAdjacencyMatrix[i][i]=0;
        res1[i][i]=0;
    }
}

void CreateGraphAdjacencyMatrix(int m){
    for(int i=0;i<m;i++){
        int s,e,w;
        cin>>s>>e>>w;
        GraphAdjacencyMatrix[s][e]=w;
    }
}

void add(int s,int e,int w){
    count++;
    edge[count].next=head[s];
    edge[count].to=e;
    edge[count].w=w;
    head[s]=count;
}

void CreateGraphAdjacencyList(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(GraphAdjacencyMatrix[i][j]!=inf&&i!=j){
                add(i,j,GraphAdjacencyMatrix[i][j]);
            }
        }
    }
}

void print(int c,int n){
    switch(c){
        case 1:
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(GraphAdjacencyMatrix[i][j]==inf){
                        cout<<setw(5)<<"inf"<<" ";
                    }
                    else{
                        cout<<setw(5)<<GraphAdjacencyMatrix[i][j]<<" ";
                    }
                }
                cout<<endl;
            }
            break;
        case 2:
            for(int i=1;i<=n;i++){
                cout<<"head:"<<i<<" ";
                for(int j=head[i];j!=-1;j=edge[j].next){
                    cout<<"to:"<<edge[j].to<<" "<<"w:"<<edge[j].w<<" ";
                }
                cout<<endl;
            }
            break;
        case 3:
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(res1[i][j]==inf){
                        cout<<setw(5)<<"inf"<<" ";
                    }
                    else{
                        cout<<setw(5)<<res1[i][j]<<" ";
                    }
                }
                cout<<endl;
            }
            break;
        case 4:
            for(int i=1;i<res2count;i++){
                cout<<res2[i]<<" ";
            }
            cout<<endl;
            break;
    }
}

void CreateMatrixFromList(int n){
    for(int i=1;i<=n;i++){
        for(int j=head[i];j!=-1;j=edge[j].next){
            res1[i][edge[j].to]=edge[j].w;
        }
    }
}

void dfsRecursion(int i){
    res2[res2count++]=i;
    vis[i]=1;
    for(int j=head[i];j!=-1;j=edge[j].next){
        if(!vis[edge[j].to]){
            dfsRecursion(edge[j].to);
        }
    }
}

void dfsNonrecursion(int i){
    stack<pair<int,int>> s;
    s.push(make_pair(i,head[i]));
    cout<<s.top().first<<" ";
    memset(vis,0,sizeof(vis));
    vis[i]=1;
    while(!s.empty()){
        pair<int,int> now=s.top();
        int nowNode=now.second;
        while(vis[edge[nowNode].to]&&nowNode!=-1){
            nowNode=edge[nowNode].next;
        }
        if(nowNode!=-1){
            vis[edge[nowNode].to]=1;
            s.push(make_pair(edge[nowNode].to,head[edge[nowNode].to]));
            cout<<edge[nowNode].to<<" ";
        }
        else{
            s.pop();
        }
    }
    cout<<endl;
}

int main(){
    init();
    int n,m;
    cin>>n>>m;
    CreateGraphAdjacencyMatrix(m);
    print(1,n);
    CreateGraphAdjacencyList(n);
    print(2,n);
    CreateMatrixFromList(n);
    print(3,n);
    dfsRecursion(1);
    print(4,n);
    dfsNonrecursion(1);
    return 0;
}

/*
6 10
1 2 5
2 3 4
4 3 5
5 4 5
6 5 1
6 1 3
1 4 7
3 1 8
3 6 9
4 6 6
*/
