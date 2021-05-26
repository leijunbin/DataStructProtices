#include "buildtree.h"
#include <iostream>
#include <stack>
#include <cstring>
#include <string>

#include "buildtree.h"
#include "bigint.h"
using namespace std;

bool buildTree::isnumber(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

bool buildTree::isope(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

int buildTree::opelevel(char c)
{
    if (c == '+' || c == '-')
        return 2;
    if (c == '*' || c == '/')
        return 1;
    if (c == '(' || c == ')')
        return 0;
    if (isnumber(c))
        return -1;
}

buildTree::buildTree()
{
    root = NULL;
}

void deletePoint(expressTree *tmp)
{
    if (tmp->lchild != NULL)
        deletePoint(tmp->lchild);
    if (tmp->rchild != NULL)
        deletePoint(tmp->rchild);
    delete tmp;
}

buildTree::~buildTree()
{
    deletePoint(root);
}

void buildTree::buildTrees(string str)
{

    expressTree *node;

    stack<expressTree *> nodeStack; //节点栈
    stack<char> opeStack;						//符号栈

    for (int i = 0; i < str.length(); i++)
    {
        if (opelevel(str[i]) == 0)
        {
            // 0号优先级 ( 和 ) 的处理
            if (str[i] == '(')
            {
                char temp = str[i];
                opeStack.push(temp);
            }
            else if (str[i] == ')')
            {
                while (opeStack.top() != '(')
                {
                    char temp = opeStack.top();
                    opeStack.pop();
                    expressTree *tmp = new expressTree;
                    tmp->m.b = temp;
                    expressTree *t1 = nodeStack.top();
                    nodeStack.pop();
                    expressTree *t2 = nodeStack.top();
                    nodeStack.pop();

                    tmp->lchild = t1;
                    tmp->rchild = t2;
                    nodeStack.push(tmp);
                }
                opeStack.pop();
            }
        }
        else if (opelevel(str[i]) == 1 || opelevel(str[i]) == 2)
        {
            if (opelevel(str[i]) == 1)
            {
                //第一优先级 * /
                while (!opeStack.empty() && opeStack.top() != '(' && opelevel(opeStack.top()) != 2)
                {
                    char temp = opeStack.top();
                    opeStack.pop();
                    expressTree *tmp = new expressTree;
                    tmp->m.b = temp;
                    expressTree *t1 = nodeStack.top();
                    nodeStack.pop();
                    expressTree *t2 = nodeStack.top();
                    nodeStack.pop();

                    tmp->lchild = t1;
                    tmp->rchild = t2;
                    nodeStack.push(tmp);
                }
            }
            else if (opelevel(str[i]) == 2)
            {
                //第二优先级 + -
                while (!opeStack.empty() && opeStack.top() != '(')
                {
                    char temp = opeStack.top();
                    opeStack.pop();
                    expressTree *tmp = new expressTree;
                    tmp->m.b = temp;
                    expressTree *t1 = nodeStack.top();
                    nodeStack.pop();
                    expressTree *t2 = nodeStack.top();
                    nodeStack.pop();

                    tmp->lchild = t1;
                    tmp->rchild = t2;
                    nodeStack.push(tmp);
                }
            }
            char temp = str[i];
            opeStack.push(temp);
        }
        else
        {
            //操作数的处理
            int begin = i;
            while (isnumber(str[i]))
            {
                i++;
            }
            char number[10000];
            memset(number,0,10000);
            int count = 0;
            for (int j = begin; j < i; j++)
            {
                number[count] = str[j];
                count++;
            }
            BigInt tmp(number);
            expressTree *temp = new expressTree;
            temp->m.a = tmp;
            nodeStack.push(temp);
            i -= 1;
        }
    }
    while (!opeStack.empty())
    {
        char temp = opeStack.top();
        opeStack.pop();
        expressTree *tmp = new expressTree;
        tmp->m.b = temp;
        expressTree *t1 = nodeStack.top();
        nodeStack.pop();
        expressTree *t2 = nodeStack.top();
        nodeStack.pop();

        tmp->lchild = t1;
        tmp->rchild = t2;
        nodeStack.push(tmp);
    }
    root = nodeStack.top();
    nodeStack.pop();
}

int falg = -1;
void preOrder(expressTree *T, point *a)
{
    if (T == NULL)
        return;
    falg++;
    a[falg] = T->m;
    preOrder(T->lchild, a);
    preOrder(T->rchild, a);
}

int buildTree::preorder(point *b)
{
    falg = -1;
    preOrder(root, b);
    return falg;
}

void postOrder(expressTree *T, point *a)
{
    if (T == NULL)
        return;
    postOrder(T->lchild, a);
    postOrder(T->rchild, a);
    falg++;
    a[falg] = T->m;
}

int buildTree::postorder(point *b)
{
    falg = -1;
    postOrder(root, b);
    return falg;
}
