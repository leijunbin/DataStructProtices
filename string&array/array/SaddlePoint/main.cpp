#include<iostream>
using namespace std;
const int maxn=1e4+10;
int matrix[maxn][maxn];
int n;

void solve(){
    int res=0;
    for(int i=0;i<n;i++){
        int position=-1;
        int min=0x3f3f3f3f;
        for(int j=0;j<n;j++){
            if(matrix[i][j]<min){
                min=matrix[i][j];
                position=j;
            }
        }
        int j;
        for(j=0;j<n;j++){
            if(matrix[j][position]>matrix[i][j]&&j!=i){
                break;
            }
        }
        if(j==n){
            cout<<"x:"<<i<<" "<<"y:"<<position<<" "<<"data:"<<matrix[i][position]<<endl;
            res++;
        }
    }
    cout<<res<<endl;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    solve();
    return 0;
}
/*
4
9 7 6 8
20 26 22 25
28 36 25 30
12 4 2 6
 */
