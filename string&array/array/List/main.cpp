#include<iostream>
using namespace std;

const int maxn=1e5+10;
char a[maxn];

enum TYPE{
    HEAD_TYPE,
    VALUE_TYPE,
    SUB_TYPE,
};

struct GeneralizeNode{
    GeneralizeNode(TYPE type,const char& value=0)
        :_type(type),_next(NULL),_sublink(NULL){
        _value=value;
    }
    TYPE _type;
    GeneralizeNode* _next;
    union{
        char _value;
        GeneralizeNode* _sublink;
    };
};

class GeneralizeNodeList{
    typedef GeneralizeNode node;
public:
    GeneralizeNodeList():_head(NULL){}
    GeneralizeNodeList(const char *str):_head(NULL){
        _head=_CreatList(str);
    }
    GeneralizeNodeList(const GeneralizeNodeList& g){
        _head=_copy(g._head);
    }
    ~GeneralizeNodeList(){
        Destory(_head);
    }
    GeneralizeNodeList& operator=(const GeneralizeNodeList& g){
        if(this!=&g){
            _head=g._head;
        }
        return *this;
    }
    int size(){
        return _size(_head);
    }
    int depth(){
        return _depth(_head);
    }
    void print(){
        _print(_head);
    }
protected:
    bool judge(const char& value){
        if((value>='0'&&value<='9')||(value>='a'&&value<='z')||(value>='A'&&value<='Z'))
            return true;
        else
            return false;
    }
    node* _CreatList(const char*& str){
        node* head=new node(HEAD_TYPE,*str);
        node* prev=head;
        ++str;
        while(*str){
            if(judge(*str)){
                node* head=new node(VALUE_TYPE,*str);
                prev->_next=head;
                prev=prev->_next;
                ++str;
            }
            else if(*str=='('){
                node* head=new node(SUB_TYPE,*str);
                prev->_next=head;
                prev=prev->_next;
                prev->_sublink=_CreatList(str);
            }
            else if(*str==')'){
                prev->_next=NULL;
                ++str;
                return head;
            }
            else
                str++;
        }
         return head;
    }
    node *_copy(node* copyhead){
        if(copyhead==NULL)
            return NULL;
        node* newhead=new node(HEAD_TYPE,copyhead->_value);
        node* prev=newhead;
        node* cur=copyhead->_next;
        while(cur){
            if(cur->_type==VALUE_TYPE){
                node* tmp=new node(VALUE_TYPE,cur->_value);
                prev->_next=tmp;
                prev=prev->_next;
                cur=cur->_next;
            }
            else if(cur->_type==SUB_TYPE){
                node* tmp=new node(SUB_TYPE);
                prev->_next=tmp;
                prev=prev->_next;
                tmp->_sublink=_copy(cur->_sublink);
                cur=cur->_next;
            }
            else
                cur=cur->_next;
        }
        return newhead;
    }
    void Destory(node* head){
        node* cur=head;
        while(cur){
            node* del=cur;
            if(cur->_type==SUB_TYPE){
                Destory(cur->_sublink);
            }
            cur=cur->_next;
            delete del;
        }
    }
    int _size(node* head){
        node* cur=head;
        int count=0;
        while(cur){
            if(cur->_type==VALUE_TYPE){
                count++;
            }
            else if(cur->_type==SUB_TYPE){
                count+=_size(cur->_sublink);
            }
            cur=cur->_next;
        }
        return count;
    }
    int _depth(node* head){
        node* cur=head;
        int maxdepth=1;
        while(cur){
            int depth=1;
            if(cur->_type==SUB_TYPE){
                depth+=_depth(cur->_sublink);
                if(depth>maxdepth){
                    maxdepth=depth;
                }
            }
            cur=cur->_next;
        }
        return maxdepth;
    }
    void _print(node* head){
        if(head==NULL)
            return;
        node* cur=head;
        while(cur){
            if(cur->_type==VALUE_TYPE){
                cout<<cur->_value;
                if(cur->_next!=NULL){
                    cout<<",";
                }
                cur=cur->_next;
            }
            else if(cur->_type==SUB_TYPE){
                _print(cur->_sublink);
                if(cur->_next!=NULL){
                    cout<<",";
                }
                cur=cur->_next;
            }
            else{
                cout<<"(";
                cur=cur->_next;
            }
        }
        cout<<")";
    }
protected:
    node* _head;
};

int main(){
    cin>>a;
    GeneralizeNodeList g(a);
    cout<<g.size()<<" "<<g.depth()<<endl;
    return 0;
}

/* (b,(b,a,(),d),((a,b),c,(()))) */
