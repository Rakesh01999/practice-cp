#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void print_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
}

void insert_at_tail_opt(Node* head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode ;
        tail = newNode;
        return ;
    }
    tail->next=newNode;
    tail = newNode;
}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *tail = new Node(40);

    head->next = a;
    a->next = b;
    b->next = tail;

    insert_at_tail_opt(head, tail, 100);
    print_list(head);

    return 0;
}
