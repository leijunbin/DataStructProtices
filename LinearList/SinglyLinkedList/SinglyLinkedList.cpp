#include "SinglyLinkedList.h"

List::List(){}

List::~List(){
    while(first != NULL){
        LinkNode *del =first;
        first = first -> link;
        delete del;
    }
}

ElementData List::Search(int i){
    LinkNode *current = first;
    for(int k = 1; current != NULL && k < i; k++){
        current = current -> link;
    }
    if(current == NULL || current -> link == NULL)
        return '\0';
    else{
        return current -> data;
    }
}

int List::Location(ElementData &x){
    LinkNode *current = first;
    int res = 1;
    while(current != NULL){
        if(current -> data == x){
            return res;
        }
        else{
            current = current -> link;
            res++;
        }
    }
    if(current == NULL)
        return -1;
}

bool List::Insert(int i, ElementData &x){
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

bool List::Remove(int i, ElementData &x){
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
    x = del -> data;
    delete del;
    return true;
}

bool List::isEmpty() const{
    return (first == NULL) ? true : false;
}

void List::input(){
    int maxSize;
    cout << "Begin build sequential list, please input number in this sequential list:";
    cin >> maxSize;
    for(int i = 0; i < maxSize; i++){
        ElementData data;
        cin >> data;
        Insert(i, data);
    }
}

void List::output(){
    int res = 0;
    LinkNode *current = first;
    while(current != NULL){
        cout << "#" << res + 1 << ":" << current -> data << endl;
        current = current -> link;
        res++;
    }
    cout << "Sequential list the last location:" << res << endl;
}
