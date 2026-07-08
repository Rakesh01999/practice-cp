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

int main(){
    // Node a(10), b(20), c(30);
    Node* head=new Node(10);
    Node* a=new Node(30);
    Node* b=new Node(40);
    Node* c=new Node(50);
    
    head->next=a;
    a->next=b;
    b->next=c;

    // cout<<head->val<<" "<<a->val<<" "<<b->val<<" "<<c->val<<endl;
    cout<<head->val<<" ";
    cout<<head->next->val<<" ";
    cout<<head->next->next->val<<" ";
    cout<<head->next->next->next->val<<" ";

}