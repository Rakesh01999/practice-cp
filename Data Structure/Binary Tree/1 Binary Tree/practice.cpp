#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

// void preOrder(Node* root){
//     if (root == NULL)
//     {
//         return ;
//     }
//     cout<<root->val<<" ";   //root
//     preOrder(root->left);   //left
//     preOrder(root->right);   //right
// }

// void inOrder(Node* root){
//     if(root == NULL) return ;
//     inOrder(root->left);
//     cout<<root->val<<" ";
//     inOrder(root->right);
// }

void postOrder(Node* root){
    if(root == NULL) return ;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}


int main(){
    Node* root = new Node(10);
    Node* a = new Node(8);
    Node* b = new Node(12);
    Node* c = new Node(7);
    Node* d = new Node(11);
    Node* e = new Node(13);

    root->left=a;
    root->right=b;
    a->left=c;
    b->left=d;
    b->right=e;

    // preOrder(root);
    // inOrder(root);
    postOrder(root);

    return 0;
}