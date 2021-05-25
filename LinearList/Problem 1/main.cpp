#include<iostream>
using namespace std;

struct node{
    double data;
    node* next;
    node(node* add=NULL,double a=0)
        :data(a),next(add){}
};
node* start;


void init(){
    start=new node;
}

void add(double a){
    node* current=start;
    while(!(current->next==NULL)){
        current=current->next;
    }
    node* newNode=new node;
    newNode->data=a;
    newNode->next=current->next;
    current->next=newNode;
}

int findNumber(int x){
    node* current=start;
    int count=0;
    while(!(current->next==NULL)){
        current=current->next;
        count++;
        if(current->data==x){
            return count;
        }
    }
    return -1;
}

int nodeNumber(){
    node* current=start;
    int count=0;
    while(!(current->next==NULL)){
        current=current->next;
        count++;
    }
    return count;
}

node* findaddress(int count){
    node* current=start;
    int countl=0;
    while(!(current->next==NULL)){
        current=current->next;
        countl++;
        if(countl==count){
            return current;
        }
    }
    return NULL;
}

void print(){
    node* current=start;
    while(!(current->next==NULL)){
        current=current->next;
        cout<<current->data<<" ";
    }
    cout<<endl;
}

void swapm(int a,int b){
    node* an=findaddress(a);
    node* bn=findaddress(b);
    double temp=an->data;
    an->data=bn->data;
    bn->data=temp;
}

void sloveProblem(double x){
    int place=findNumber(x);
    if(place==-1){
        cout<<"Please check your input number."<<endl;
    }
    int i=1,j=nodeNumber();
    node* left=findaddress(i);
    node* right=findaddress(j);
    while(1){
        while(right->data>x){
            j--;
            right=findaddress(j);
        }
        while(left->data<x){
            i++;
            left=findaddress(i);
        }
        if(i>=j)
            break;
        swapm(i,j);
        if(findaddress(i)->data==findaddress(j)->data){
            int k;
            for(k=i+1;k<j;k++){
                if(findaddress(i)->data!=findaddress(k)->data)
                    break;
            }
            if(k==j){
                break;
            }
        }
    }
}

void deletek(){
    node* current=start;
    while(!(current->next==NULL)){
        node* deletem=current;
        current=current->next;
        delete deletem;
    }
}

int main(){
    init();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        double input;
        cin>>input;
        add(input);
    }
    double res;
    cin>>res;
    sloveProblem(res);
    print();
    deletek();
    return 0;
}
