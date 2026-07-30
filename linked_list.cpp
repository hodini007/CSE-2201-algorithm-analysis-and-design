#include<bits/stdc++.h>
using namespace std;


class node{

    public :
    int data ;
    node* next ;

    node(){
        data=0;
        next=NULL;

    }

    node(int n){
        this->data=n;
        this->next=NULL;
    }
};

class linked_list{
    public:
    node* head;
    linked_list(){
        head=NULL;
    }

    void insert_node(int n){
        node* x=new node(n);
        if(head==NULL){
            head=x;
            return;
        }

        x->next=this->head;
    }


    
};