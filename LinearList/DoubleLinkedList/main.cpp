#include "DoubleLinkedList.h"


int main(){
    cout<<"(1)初始化双链表H"<<endl;
    DblList<char> h(0);
    cout<<"(2)依次采用尾插法插入a,b,c,d,e元素"<<endl;
    h.Insert(0, 'a', 1);
    h.Insert(1, 'b', 1);
    h.Insert(2, 'c', 1);
    h.Insert(3, 'd', 1);
    h.Insert(4, 'e', 1);
    cout<<"(3)输出双链表H及H的长度：";
    h.output();
    cout<<" "<<h.Length()<<endl;
    cout<<"(4)判断双链表H是否为空：";
    cout<<h.IsEmpty()<<endl;
    cout<<"(5)输出双链表H的第三个元素：";
    cout<<(h.Locate(3, 1)->data)<<endl;
    char temp = 'd';
    cout<<"(6)输出元素d的位置：";
    cout<<h.Search(temp)<<endl;
    temp = 'f';
    cout<<"(7)在第4个元素位置上插入f元素"<<endl;
    h.Insert(4, temp, 1);
    cout<<"(8)删除H的第三个元素"<<endl;
    h.Remove(3, temp, 1);
    cout<<"(9)输出双链表：";
    h.output();
    cout<<endl<<"(10)释放双链表";
    h.~DblList();
    return 0;
}
