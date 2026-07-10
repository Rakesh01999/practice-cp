#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val=val;
        this->prev=NULL;
        this->next=NULL;
    }
};

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next=a;
    a->next=tail;
    a->prev=head;
    tail->prev=a;
    return 0;
}