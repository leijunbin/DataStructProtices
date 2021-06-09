#include<iostream>
#include<assert.h>
using namespace std;
const int maxSize=50;

template<class T>
class Queue{
public:
    Queue(){};
    ~Queue(){};
    virtual bool EnQueue(const T& x)=0;
    virtual bool DeQueue(T& x)=0;
    virtual bool getFront(T& x)=0;
    virtual bool IsEmpty()const=0;
    virtual bool IsFull()const=0;
    virtual int getSize()const=0;
};

template<class T>
class SeqQueue:public Queue<T>{
public:
    SeqQueue(int sz=10);
    ~SeqQueue(){delete[]elements;}
    bool EnQueue(const T &x);
    bool DeQueue(T &x);
    bool getFront(T &x);
    void makeEmpty(){front=rear=0;}
    bool IsEmpty()const{return (front==rear)?true:false;}
    bool IsFull()const{return ((rear+1)%maxSize==front)?true:false;}
    int getSize()const{return (rear-front+maxSize)%maxSize;}
    template<class T2>
    friend ostream& operator<<(ostream& os,SeqQueue<T2>& Q);
protected:
    int front,rear;
    T *elements;
    int maxSize;
};

template<class T>
SeqQueue<T>::SeqQueue(int sz):front(0),rear(0),maxSize(sz){
    elements=new T[maxSize];
    assert(elements!=NULL);
}

template<class T>
bool SeqQueue<T>::EnQueue(const T& x){
    if(IsFull()==true)
        return false;
    elements[rear]=x;
    rear=(rear+1)%maxSize;
    return true;
}

template<class T>
bool SeqQueue<T>::DeQueue(T& x){
    if(IsEmpty()==true)
        return false;
    x=elements[front];
    front=(front+1)%maxSize;
    return true;
}

template<class T>
bool SeqQueue<T>::getFront(T& x){
    if(IsEmpty()==true)
        return false;
    x=elements[front];
    return true;
}

template<class T>
ostream& operator<<(ostream& os,SeqQueue<T>& Q){
    os<<"front="<<Q.front<<",rear="<<Q.rear<<endl;
    for(int i=Q.front;i!=Q.rear;i=(i+1)%maxSize)
        os<<i<<":"<<Q.elements[i]<<endl;
    return os;
}

int main()
{
    char x;
    SeqQueue<char> m;
    if(m.IsEmpty())
        cout<<"队列为空"<<endl;
    else cout<<"队列不为空"<<endl;
    for(int i=0;i<3;++i)
        m.EnQueue(97+i);
    if(m.DeQueue(x))
        cout<<"出队元素为:"<<x<<endl;
    else cout<<"出队失败!"<<endl;
    cout<<"队列元素个数为:"<<m.getSize()<<endl;
    for(int i=0;i<3;++i)
        m.EnQueue(100+i);
    cout<<m;
    m.~SeqQueue();
    return 0;
}

