#include<iostream>
using namespace std;

typedef enum PointerTag{
    Link, Thread
}PT;

typedef struct ThrBiNode{
    char data;
    int height;
    ThrBiNode *lchild,*rchild;
    PT lTag=Link,rTag=Link;
}ThrBiNode;

ThrBiNode *root;

void createTree(ThrBiNode *&root,int height){
    char a;
    a=getchar();
    if(a==' '){
        root=NULL;
        return;
    }
    else if(a=='\n')
        return;
    else{
        ThrBiNode *newNode=new ThrBiNode;
        root=newNode;
        newNode->data=a;
        newNode->height=height;
        createTree(newNode->lchild,height+1);
        createTree(newNode->rchild,height+1);
        return;
    }
}

void inThreading(ThrBiNode *root,ThrBiNode *&pre){
    if(root){
        if(root->lchild)
            inThreading(root->lchild,pre);

        if(!root->lchild){
            root->lTag=Thread;
            root->lchild=pre;
        }

        if(pre!=NULL){
            if(!pre->rchild){
                pre->rTag=Thread;
                pre->rchild=root;
            }
        }
        pre=root;

        if(root->rchild)
            inThreading(root->rchild,pre);
    }
}

void InOrderRecursion(ThrBiNode *root){
    if(root){
        if(root->lTag==Link)
            InOrderRecursion(root->lchild);
        cout<<root->data<<" ";
        if(root->rTag==Link)
            InOrderRecursion(root->rchild);
    }
}

void InOrderUnrecursion(ThrBiNode *root){
    ThrBiNode* current=root;
    while(current){
        while(current->lTag==Link){
            current=current->lchild;
        }
        cout<<current->data<<" ";
        while(current->rTag==Thread&&current->rchild!=NULL){
            current=current->rchild;
            cout<<current->data<<" ";
        }
        current=current->rchild;
    }
}

void findNode(ThrBiNode* root,char &find,ThrBiNode *&res){
    if(root){
        if(root->lTag==Link)
            findNode(root->lchild,find,res);
        if(root->data==find)
            res=root;
        if(root->rTag==Link)
            findNode(root->rchild,find,res);
    }
}

void findBeforeandBehind(ThrBiNode* root,char &find){
    ThrBiNode* current;
    findNode(root,find,current);
    if(current->lTag==Thread){
        cout<<"Before:"<<current->lchild->data<<endl;
    }
    else{
        ThrBiNode* p;
        for(p=current->lchild;p->rTag==Link;p=p->rchild);
        cout<<"Before:"<<p->data<<endl;
    }
    findNode(root,find,current);
    if(current->rTag==Thread){
        cout<<"Behind:"<<current->rchild->data<<endl;
    }
    else if(current->lchild){
        ThrBiNode* p;
        for(p=current->rchild;p->lTag==Link;p=p->lchild);
        cout<<"Behind:"<<p->data<<endl;
    }
}

int main(){
    createTree(root,1);
    ThrBiNode *temp=NULL;
    inThreading(root,temp);
    cout<<"Recursion InOrder:"<<endl;
    InOrderRecursion(root);
    cout<<endl;
    cout<<"Unrecursion InOrder:"<<endl;
    InOrderUnrecursion(root);
    cout<<endl;
    char find;
    cin>>find;
    findBeforeandBehind(root,find);
    return 0;
}
/*
ABC  E  DFY   G
 */
