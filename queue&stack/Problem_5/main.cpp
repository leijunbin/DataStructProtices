#include<iostream>
#include<queue>
using namespace std;
queue<int> q;

void menu(){
    printf("1.排队\n2.就诊\n3.查看排队\n4.不再排队,余下依次就诊\n5.下班");
    printf("\n");
}

int main(){
    int choice;
    while(1){
        menu();
        cout<<"Please put your choice:";
        cin>>choice;
        if(choice==5){
            cout<<"下班！"<<endl;
            break;
        }
        else if(choice==4){
            cout<<"不再排队!"<<endl;
            cout<<"就诊病人号：";
            while(!q.empty()){
                cout<<q.front()<<" ";
                q.pop();
            }
            cout<<endl;
        }
        else if(choice==3){
            cout<<"就诊病人号：";
            int size=q.size();
            int temp[size];
            for(int i=0;i<size;i++){
                temp[i]=q.front();
                cout<<temp[i];
                q.pop();
            }
            for(int i=0;i<size;i++){
                q.push(temp[i]);
            }
            cout<<endl;
        }
        else if(choice==2){
            cout<<"就诊病人号：";
            cout<<q.front()<<endl;
            q.pop();
            cout<<endl;
        }
        else if(choice==1){
            cout<<"排队病人号：";
            int test;
            cin>>test;
            q.push(test);
        }
        else{
            cout<<"Please check your input"<<endl;
            continue;
        }
    }
}
