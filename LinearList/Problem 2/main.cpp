#include<iostream>
using namespace std;

template <class T>
struct node{
    T data;
    node<T>* next;
    node(){
        next=NULL;
    }
};

template <class T>
class Link{
    public:
        Link(){
            start1=new node<T>;
            start2=new node<T>;
            res=new node<T>;
        }

        ~Link(){
            node<T>* current=start1;
            while(!(current->next==NULL)){
                node<T>* deletem=current;
                current=current->next;
                delete deletem;
            }
            current=start2;
            while(!(current->next==NULL)){
                node<T>* deletem=current;
                current=current->next;
                delete deletem;
            }
            current=res;
            while(!(current->next==NULL)){
                node<T>* deletem=current;
                current=current->next;
                delete deletem;
            }
        }

        void deleteR(){
            node<T> *current=res;
            while(!(current->next==NULL)){
                node<T>* deletem=current;
                current=current->next;
                delete deletem;
            }
            res=new node<T>;
        }

        void addT(int i,T data){
            node<T> *current,*newNode;
            switch(i){
                case 1:
                    current=start1;
                    break;
                case 2:
                    current=start2;
                    break;
                case 3:
                    current=res;
                    break;
            }
            while(!(current->next==NULL)){
                current=current->next;
            }
            newNode=new node<T>;
            newNode->data=data;
            newNode->next=current->next;
            current->next=newNode;
        }
        
        int getSize(int i){
            int count=0;
            node<T>* current;
            switch(i){
                case 1:
                    current=start1;
                    while(!(current->next==NULL)){
                        current=current->next;
                        count++;
                    }
                    break;
                case 2:
                    current=start2;
                    while(!(current->next==NULL)){
                        current=current->next;
                        count++;
                    }
                    break;
                case 3:
                    current=res;
                    while(!(current->next==NULL)){
                        current=current->next;
                        count++;
                    }
                    break;
            }
            return count;
		}

        node<T>* findT(int i,T data){
            node<T>* current;
            switch(i){
                case 1:current=start1;break;
                case 2:current=start2;break;
                case 3:current=res;break;
            }

            int falg=0;
            while(!(current->next==NULL)){
                current=current->next;
                if(current->data==data){
                    falg=1;
                    break;
                }
            }
            if(falg==0)
                return NULL;
            else
                return current;
        }

        void add(){
            int start1n=getSize(1);
            int start2n=getSize(2);
            node<T>* current1=start1;
            node<T>* current2=start2;
            node<T>* o;
            int i=0,j=0;
            while(i<start1n&&j<start2n){
                current1=current1->next;
                o=findT(3,current1->data);
                if(o==NULL){
                    addT(3,current1->data);
                }
                i++;
                current2=current2->next;
                o=findT(3,current2->data);
                if(o==NULL){
                    addT(3,current2->data);
                }
                j++;
            }
            while(i==start1n&&j<start2n){
                current2=current2->next;
                o=findT(3,current2->data);
                if(o==NULL){
                    addT(3,current2->data);
                }
                j++;
            }
            while(j==start2n&&i<start1n){
                current1=current1->next;
                node<T>* o=findT(3,current1->data);
                if(o==NULL){
                    addT(3,current1->data);
                }
                i++;
            }
        }

        void minu(){
            int start1n=getSize(1);
            node<T>* current1=start1;
            node<T>* o;
            int i=0;
            while(i<start1n){
                current1=current1->next;
                o=findT(2,current1->data);
                if(o==NULL){
                    addT(3,current1->data);
                }
                i++;
            }
        }

        void jiao(){
            int start1n=getSize(1);
            node<T>* current1=start1;
            node<T>* o;
            int i=0;
            while(i<start1n){
                current1=current1->next;
                o=findT(2,current1->data);
                if(!(o==NULL)){
                    addT(3,current1->data);
                }
                i++;
            }
        }

        void printf(){
            node<T>* current=res;
            while(!(current->next==NULL)){
                current=current->next;
                cout<<current->data<<" ";
            }
            cout<<endl;
        }

    private:
        node<T>* start1;
        node<T>* start2;
        node<T>* res;
};

int main(){
    Link<int> test;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        test.addT(1,a);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        test.addT(2,a);
    }

    test.add();
    test.printf();
    test.deleteR();

    test.minu();
    test.printf();
    test.deleteR();

    test.jiao();
    test.printf();
    test.deleteR();
    return 0;
}
