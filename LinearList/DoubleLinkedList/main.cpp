#include "DoubleLinkedList.h"


int main(){
    cout<<"(1)��ʼ��˫����H"<<endl;
    DblList<char> h(0);
    cout<<"(2)���β���β�巨����a,b,c,d,eԪ��"<<endl;
    h.Insert(0, 'a', 1);
    h.Insert(1, 'b', 1);
    h.Insert(2, 'c', 1);
    h.Insert(3, 'd', 1);
    h.Insert(4, 'e', 1);
    cout<<"(3)���˫����H��H�ĳ��ȣ�";
    h.output();
    cout<<" "<<h.Length()<<endl;
    cout<<"(4)�ж�˫����H�Ƿ�Ϊ�գ�";
    cout<<h.IsEmpty()<<endl;
    cout<<"(5)���˫����H�ĵ�����Ԫ�أ�";
    cout<<(h.Locate(3, 1)->data)<<endl;
    char temp = 'd';
    cout<<"(6)���Ԫ��d��λ�ã�";
    cout<<h.Search(temp)<<endl;
    temp = 'f';
    cout<<"(7)�ڵ�4��Ԫ��λ���ϲ���fԪ��"<<endl;
    h.Insert(4, temp, 1);
    cout<<"(8)ɾ��H�ĵ�����Ԫ��"<<endl;
    h.Remove(3, temp, 1);
    cout<<"(9)���˫����";
    h.output();
    cout<<endl<<"(10)�ͷ�˫����";
    h.~DblList();
    return 0;
}
