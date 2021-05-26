#include<iostream>
#include<queue>
#include<map>
#include<stack>
using namespace std;

typedef struct point{
    int x,y;
    int pre;
}point;
point success;

int maps[5][5];
point Point[100];
int luxian[110]={0};
int vis[5][5];
int count=0;
queue<point> q;
stack<point> s;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int res[100]={0};

int path=0;

void init(){
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            vis[i][j]=0;
    success.x=4,success.y=4;
    count=0,path=0;
}

bool check(point &x){
    if(x.x<0||x.x>=5||x.y<0||x.y>=5||vis[x.x][x.y]==1||maps[x.x][x.y]==0)
        return false;
    return true;
}

void bfs(point &start){
    q.push(start);
    vis[start.x][start.y]=1;
    Point[count++]=start;
    while(!q.empty()){
        point now=q.front();
        q.pop();
        Point[count++]=now;
        if(now.x==success.x&&now.y==success.y){
            if(path==0){
                cout<<"You find the minLength path."<<endl;
            }
            s.push(now);
            while(!(now.pre==-1)){
                now=Point[now.pre];
                s.push(now);
            }
            int step=1;
            while(!s.empty()){
                cout<<step++<<" "<<s.top().x<<" "<<s.top().y<<endl;
                s.pop();
            }
            cout<<step-2<<endl<<endl;
            path++;
            continue;
        }
        point next;
        for(int i=0;i<4;i++){
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            next.pre=count-1;
            if(check(next)){
                vis[next.x][next.y]=1;
                q.push(next);
            }
        }
    }
}

void dfs(point &start,int step){
    point now=start;
    point next;
    Point[count++]=now;
    if(now.x==success.x&&now.y==success.y){
        Point[step++]=now;
        if(path==0){
            cout<<"All path here."<<endl;
        }
        int steps=1;
        int i=0;
        while(i<step){
            cout<<steps++<<" "<<Point[res[i]].x<<" "<<Point[res[i]].y<<endl;
            i++;
        }
        cout<<steps-2<<endl<<endl;
        path++;
        return;
    }
    for(int i=0;i<4;i++){
        next.x=now.x+dir[i][0];
        next.y=now.y+dir[i][1];
        next.pre=count-1;
        if(check(next)){
            vis[next.x][next.y]=1;
            res[step]=count-1;
            dfs(next,step+1);
            vis[next.x][next.y]=0;
            count--;
        }
    }
}

int main(){
    init();
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            cin>>maps[i][j];
    }
    point start;
    start.x=0,start.y=0,start.pre=-1;
    bfs(start);
    init();
    vis[0][0]=1;
    res[0]=0;
    dfs(start,0);
    return 0;
}

/*
1 1 1 1 1
1 0 0 1 0
1 0 1 1 1
1 1 1 0 1
1 0 0 1 1 */
