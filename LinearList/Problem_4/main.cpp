#include <iostream>
using namespace std;

struct LinkNode{
    string checi,kaidian,daodian,start,end;
    LinkNode *link;
    LinkNode(){}
    bool operator ==(LinkNode &a){
        if(checi==a.checi&&kaidian==a.kaidian&&daodian==a.daodian&&start==a.start&&end==a.end)
            return true;
        return false;
    }
};

class Listm{
public:
    Listm(){}
    ~Listm(){
        while(first != NULL){
            LinkNode *del =first;
            first = first -> link;
            delete del;
        }
    }
    LinkNode *Search(int i){
        LinkNode *current = first;
        for(int k = 1; current != NULL && k < i; k++){
            current = current -> link;
        }
        if(current == NULL || current -> link == NULL)
            return NULL;
        else{
            return current;
        }
    }
    int Location(LinkNode &x){
        LinkNode *current = first;
        int res = 1;
        while(current != NULL){
            if(*current == x){
                return res;
            }
            else{
                current = current -> link;
                res++;
            }
        }
        if(current == NULL)
            return -1;
        else
            return res;
    }
    bool Insert(int i, LinkNode &x){
        if(first == NULL || i==0){
            LinkNode *newNode = new LinkNode(x);
            if(newNode == NULL){
                cout << "Memory allocation error." << endl;
                exit(1);
            }
            newNode -> link = first;
            first = newNode;
        }
        else{
            LinkNode *current = first;
            for(int k = 1; k < i; k++){
                if(current == NULL)
                    break;
                else
                    current = current -> link;
            }
            if(current == NULL){
                cout << "Please check the number you input." << endl;
                return false;
            }
            else{
                LinkNode *newNode = new LinkNode(x);
                if(newNode == NULL){
                    cout << "Memory allocation error." << endl;
                    exit(1);
                }
                newNode -> link = current -> link;
                current -> link = newNode;
            }
        }
        return true;
    }
    bool Remove(int i, LinkNode &x){
        LinkNode *del,*current;
        if(i <= 1){
            del = first;
            first = first -> link;
        }
        else{
            current = first;
            for(int k = 1; k < i - 1; k++){
                if(current == NULL)
                    break;
                else
                    current = current -> link;
            }
            if(current == NULL || current -> link == NULL){
                cout << "Please check the number you input."<<endl;
                return false;
            }
            del = current -> link;
            current -> link = del -> link;
        }
        x = *del;
        delete del;
        return true;
    }
    bool isEmpty() const{
        return (first == NULL) ? true : false;
    }
    void input(){
        int maxSize;
        cout << "Begin build sequential list, please input number in this sequential list:";
        cin >> maxSize;
        for(int i = 0; i < maxSize; i++){
            LinkNode data;
            cin >> data.checi >> data.kaidian >> data.daodian >> data.start >> data.end;
            Insert(i, data);
        }
    }
    void output(){
        int res = 0;
        LinkNode *current = first;
        while(current != NULL){
            cout << "#" << res + 1 << ":" << current->checi << " " << current->kaidian << " " << current->daodian << " " << current->start << " " << current->end << endl;
            current = current -> link;
            res++;
        }
        cout << "Sequential list the last location:" << res << endl;
    }
private:
    LinkNode *first = NULL;
};

int main(){
    Listm test;
    test.input();
    test.output();
    LinkNode x;
    test.Remove(2,x);
    test.output();
}
