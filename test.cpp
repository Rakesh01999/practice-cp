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

void insert_in_list(Node* &head, Node* &tail, int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return ;
    }
    tail->next=newNode;
    tail=newNode;
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

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    int val;
    while (true)
    {
        cin>>val;
        if(val==-1)
            break;
        insert_in_list(head, tail, val);
    }
    print_list(head);
    print_list_rev(head);
    
}