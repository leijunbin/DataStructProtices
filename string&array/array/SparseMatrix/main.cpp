#include<iostream>
#include<map>
using namespace std;
const int maxn=1e5+100;
map<pair<int,int>,int> mp;

struct matrix{
    int x,y;
    int data;
}matrix[maxn];

int count=0;
int inp1=0;
int inp2=0;
int res=0;

void add(int x,int y,int data){
    matrix[count].data=data;
    matrix[count].x=x;
    matrix[count++].y=y;
}

void transposition(){
    for(int i=inp1;i<inp2;i++){
        cout<<"data:"<<matrix[i].data
           <<" "<<"x:"<<matrix[i].y
           <<" "<<"y:"<<matrix[i].x;
        cout<<endl;
    }
    cout<<endl;
}

void addMatrix(){
    int res=count;
    for(int i=0;i<res;i++){
         if(mp[make_pair(matrix[i].x,matrix[i].y)]==0){
             add(matrix[i].x,matrix[i].y,matrix[i].data);
             mp[make_pair(matrix[i].x,matrix[i].y)]=count-1;
         }
         else{
             int a=mp[make_pair(matrix[i].x,matrix[i].y)];
             matrix[a].data+=matrix[i].data;
         }
    }
    for(int i=res;i<count;i++){
        cout<<"data:"<<matrix[i].data
           <<" "<<"x:"<<matrix[i].x
           <<" "<<"y:"<<matrix[i].y;
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    mp.clear();
    inp1=count;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            int a;
            cin>>a;
            if(a!=0)
                add(i,j,a);
        }
    inp2=count;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            int a;
            cin>>a;
            if(a!=0)
                add(i,j,a);
        }
    transposition();
    addMatrix();
    return 0;
}
/*
1 0 3 0
0 1 0 0
0 0 1 0
0 0 1 1

3 0 0 0
0 4 0 0
0 0 1 0
0 0 0 2
*/


