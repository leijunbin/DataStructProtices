#include<iostream>
using namespace std;

template <class T>
class stack{
    public:
        stack(int n){
            dataP=new T[n];
            maxN=n;
            count=0;
        }
        ~stack(){
            delete []dataP;
        }
        bool isEmpty(){
            return (count==0);
        }
        void push(T x){
            if(count<maxN){
                dataP[count]=x;
                count++;
            }
        }
        int size(){
            return count;
        }
        T pop(){
            if(count>0){
                T temp=dataP[--count];
                return temp;
            }
            return (T)NULL;
        }

        void prints(){
            for(int i=count-1;i>=0;i--){
                cout<<dataP[i]<<" ";
            }
            cout<<endl;
        }

    private:
        T *dataP;
        int count,maxN;
};

int main(){
    stack<char> s(100);
    if(s.isEmpty()){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');
    cout<<s.size()<<endl;
    s.prints();
    while(!(s.isEmpty())){
        char temp=s.pop();
        cout<<temp<<" ";
    }
    s.~stack();
    return 0;
}
