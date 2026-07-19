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

Node* input_tree(){
    int val;cin>>val;
    Node* root;
    if(val==-1) root=NULL;
    else root=new Node(val);
    queue<Node*>q;
    if(root)q.push(root);
    while (!q.empty())
    {
        // Node Out
        Node* f=q.front();
        q.pop();

        // Work with Node
        int l, r;cin>>l>>r;
        Node *myLeft, *myRight;
        if(l==-1) myLeft=NULL;
        else myLeft=new Node(l);
        if(r==-1) myRight=NULL;
        else myRight=new Node(r);
        f->left=myLeft;
        f->right=myRight;

        // Children of Node -push
        if(f->left)q.push(f->left);
        if(f->right)q.push(f->right);
    }
    return root;
}

void level_order(Node* root){
    if(root==NULL){
        cout<<"No Tree"<<endl;
        return ;
    }
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        // Node ber koro
        Node* f=q.front();
        q.pop();

        // Node niye kaj
        cout<<f->val<<endl;

        // Noder children push
        if(f->left)q.push(f->left);
        if(f->right)q.push(f->right);
    }    
}

int Nodes_cnt(Node* root){
    if(root==NULL)return 0;
    int l=Nodes_cnt(root->left);
    int r=Nodes_cnt(root->right);
    return l+r+1;
}

int main(){
    Node* root=input_tree();
    level_order(root);
    cout<<"total Nodes="<<Nodes_cnt(root)<<endl;
    return 0;
}