#include<bits/stdc++.h>
using namespace std;
int cnt = 0;

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

Node* input_tree(){
    int val;cin>>val;
    Node* root;
    if(val == -1) root = NULL;
    else root = new Node(val);
    queue<Node* >q;
    q.push(root);
    while (!q.empty())
    {
        Node* f = q.front();
        q.pop();

        int l,r;cin>>l>>r;
        Node* myLeft, *myRight;
        if(l == -1) myLeft = NULL;
        else myLeft = new Node(l);
        if(r == -1) myRight = NULL;
        else myRight = new Node(r);

        f->left = myLeft;
        f->right = myRight;

        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
    return root;
}

// void level_order(Node* root){
//     if(root == NULL){
//         cout<<"No Tree !"<<endl;
//         return;
//     }
//     queue<Node* >q;
//     q.push(root);
//     while (!q.empty())
//     {
//         Node* f = q.front();
//         q.pop();
//         cout<<f->val<<" ";
//         cnt++;
//         if(f->left) q.push(f->left);
//         if(f->right) q.push(f->right);
//     }
// }

// int count_nodes(Node* root){
//     if(root == NULL)
//         return 0;
//     int l = count_nodes(root->left);
//     int r = count_nodes(root->right);
//     return l+r+1;
// }

int count_leaf_nodes(Node* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    int l = count_leaf_nodes(root->left);
    int r = count_leaf_nodes(root->right);
    return l+r;
}

int main(){
    Node* root = input_tree();
    // level_order(root);
    // cout<<endl<<"No of nodes :"<<cnt<<endl;
    // cout<<"No of nodes :"<<count_nodes(root)<<endl;
    cout<<"No of nodes :"<<count_leaf_nodes(root)<<endl;

    return 0;
}