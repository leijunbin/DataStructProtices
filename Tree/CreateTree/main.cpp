#include<iostream>
using namespace std;

struct tree{
    int data = 0;
    struct tree *lchild = NULL;
    struct tree *rchild = NULL;
};

int number1[40], number2[40], number3[40], n;

void normalorder(tree *root,int a,int b,int c,int d){
    root->data = number1[a];
    int m = c;
    while(number1[a]!=number2[m])
        m++;

    if(a<=a+m-c-1&&c<=m-1){
        root->lchild = new tree;
        normalorder(root->lchild, a + 1, a + m - c, c, m - 1);
    }

    if(a+m-c<=b-1&&m+1<=d){
        root->rchild = new tree;
        normalorder(root->rchild, a + m - c + 1, b, m + 1, d);
    }
}
int count = 0;

void postorder(tree *root){
    if(root!=NULL){
        postorder(root->lchild);
        postorder(root->rchild);
        number3[count] = root->data;
        count++;
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> number1[i];
    for (int i = 0; i < n;i++)
        cin >> number2[i];
    tree *root = new tree;
    normalorder(root, 0, n - 1, 0, n - 1);
    postorder(root);
    cout << "postOrder:";
    for (int i = 0; i < n;i++)
        cout << " " << number3[i];
    return 0;
}
/*
7
4 1 3 2 6 5 7
1 2 3 4 5 6 7
 */
