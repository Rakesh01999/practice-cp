#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }
    newNode->next=head;
    head=newNode;
}

void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return ;
    }
    tail->next=newNode;
    tail=newNode;
}

void insert_at_any_pos(Node* &head, Node* & tail, int idx, int val){
    Node* newNode=new Node(val);
    Node* temp=head;
    for(int i=1;i<idx;i++){
        if(temp==NULL)
            break;
        temp=temp->next;
    }
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return ;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void print_list(Node* head){
    Node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->val<<endl;
        temp=temp->next;
    }cout<<endl;    
}

void print_list_rev(Node* temp){
    if(temp==NULL)
        return;
    print_list_rev(temp->next);
    cout<<temp->val<<" ";
}

void sort_list(Node* head){
    for(Node* i=head;i!=NULL;i=i->next){
        for(Node* j=i->next;j!=NULL;j=j->next){
            if(i->val>j->val)
                swap(i->val, j->val);
        }
    }
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    int val;
    while (true)
    {
        cin>>val;
        if(val==-1)
            break;
        insert_at_tail(head, tail, val);
    }
    // insert_at_head(head, tail, 100);
    insert_at_any_pos(head, tail, 2, 100);
    // sort_list(head);
    print_list(head);
    // print_list_rev(head);
    
}