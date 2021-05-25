#include<iostream>
using namespace std;

template<class T>
class queue{
    public:
        queue(int n){
            dataP=new T[n];
            maxN=n;
            begin=0;
            end=0;
        }
        ~queue(){
            delete []dataP;
        }
        bool isEmpty(){
           return (begin==end);
        }
        void push(T data){
            dataP[++end]=data;
        }
        T pop(){
            if(begin<end){
                return dataP[++begin];
                if(begin==end){
                    begin=0,end=0;
                }
            }
            return (T)NULL;
        }
        int size(){
            return end-begin;
        }
    private:
        T *dataP;
        int maxN;
        int begin;
        int end;
};

int main(){
    queue<char> q(100);
    if(q.isEmpty()){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    q.push('a');
    q.push('b');
    q.push('c');
    cout<<q.pop()<<endl;
    q.push('d');
    q.push('e');
    q.push('f');
    while(!(q.isEmpty())){
        cout<<q.pop()<<" ";
    }
    cout<<endl;
    q.~queue();
    return 0;
}
