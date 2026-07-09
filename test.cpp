/*
1. inset at tail
2. inset at head
3. inset at any pos

4.  delete from tail
5.  delete from head
6.  delete from any pos

7. input
8. sort
9. reverse

*/



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

void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return ;
    }
    newNode->next=head;
    head=newNode;
}

void insert_at_any_pos(Node* &head, Node* &tail, int idx, int val){
    Node* newNode=new Node(val);
    Node* temp=head;
    for(int i=1;i<idx;i++){
        if(temp!=NULL)
            temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void delete_from_head(Node* &head){
    Node* deleteNode=head;
    head=head->next;
    delete deleteNode;
}

void delete_from_tail(Node* &head, Node* &tail){
    Node* temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;
    Node* deleteNode=temp->next;
    temp->next=NULL;
    delete deleteNode;
}

void sort_list(Node* head){
    for(Node* i=head;i!=NULL;i=i->next){
        for(Node* j=i->next;j!=NULL;j=j->next){
            if(i->val>j->val)
                swap(i->val, j->val);
        }
    }
}

void rev_list(Node* temp){
    if(temp==NULL)
        return ;
    rev_list(temp->next);
    cout<<temp->val<< " ";
}

void print_list(Node* head){
    Node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->val<<endl;
        temp=temp->next;
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
    // insert_at_any_pos(head, tail, 2, 100);
    // sort_list(head);
    // rev_list(head);
    // delete_from_head(head);
    delete_from_tail(head, tail);
    print_list(head);   
}