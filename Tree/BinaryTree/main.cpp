#include<iostream>
#include<stack>
using namespace std;

typedef struct node{
    int height=0;
    char data;
    struct node *lchild,*rchlid;
}node;

node *root;

void createTree(node *&root,int height){
    char a;
    a=getchar();
    if(a==' '){
        root=NULL;
        return;
    }
    else if(a=='\n')
        return;
    else{
        node *newNode=new node;
        root=newNode;
        newNode->data=a;
        newNode->height=height;
        createTree(newNode->lchild,height+1);
        createTree(newNode->rchlid,height+1);
        return;
    }
}

void InOrderRecursion(node* root){
    if(root){
        InOrderRecursion(root->lchild);
        cout<<root->data<<" ";
        InOrderRecursion(root->rchlid);
    }
}

void InOrderUnrecursion(node *root){
    if(root==NULL)
        return;
    node* current=root;
    stack<node*> s;
    while(!s.empty()||current){
        while(current){
            s.push(current);
            current=current->lchild;
        }
        if(!s.empty()){
            current=s.top();
            s.pop();
            cout<<current->data<<" ";
            current=current->rchlid;
        }
    }
}

void search(node *root,char &a){
    if(root==NULL)
        return;
    if(root->data==a){
        cout<<root->lchild->data
            <<" "<<root->rchlid->data<<endl;
    }
    else{
        search(root->lchild,a);
        search(root->rchlid,a);
    }
}

void nodeSize(node *root,int &count){
    if(root){
        nodeSize(root->lchild,count);
        count++;
        nodeSize(root->rchlid,count);
    }
}

void leafNodeSize(node *root,int &count){
    if(root){
        if(root->lchild==NULL&&root->rchlid==NULL){
            count++;
            return;
        }
        leafNodeSize(root->lchild,count);
        leafNodeSize(root->rchlid,count);
    }
}

int maxHeight=-1;
void treeHeight(node *root){
    if(root){
        treeHeight(root->lchild);
        treeHeight(root->rchlid);
        maxHeight=max(maxHeight,root->height);
    }
}

void deleteNode(node *root){
    if(root){
        deleteNode(root->lchild);
        deleteNode(root->rchlid);
        delete root;
    }
}

int main(){
    createTree(root,1);
    cout<<"Recursion InOrder:"<<endl;
    InOrderRecursion(root);
    cout<<endl;
    cout<<"Unrecursion InOrder:"<<endl;
    InOrderUnrecursion(root);
    cout<<endl;
    char prefind;
    getchar();
    cin>>prefind;
    cout<<"You find the leftchild and rightchild of the tree:"<<endl;
    search(root,prefind);
    cout<<"Node Size:"<<endl;
    int res=0;
    nodeSize(root,res);
    cout<<res<<endl;
    cout<<"Tree Height:"<<endl;
    treeHeight(root);
    cout<<maxHeight<<endl;
    cout<<"Leafnode Size:"<<endl;
    res=0;
    leafNodeSize(root,res);
    cout<<res<<endl;
    deleteNode(root);
    return 0;
}
/*
ABC  E  DFY   G
*/
