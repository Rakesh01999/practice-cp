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
    queue<Node*>q;
    if(val==-1) return NULL;
    else root=new Node(val);
    if(root) q.push(root);
    while(!q.empty()){
        // Node ber koro
        Node* f=q.front();
        q.pop();

        // Node niye kaj
        int l, r;cin>>l>>r;
        Node* myLeft;
        Node* myRight;
        if(l==-1) myLeft=NULL;
        else myLeft=new Node(l);
        
        if(r==-1) myRight=NULL;
        else myRight=new Node(r);

        f->left=myLeft;
        f->right=myRight;

        // Node er child push
        if(f->left) q.push(myLeft);
        if(f->right) q.push(myRight);
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
    while(!q.empty()){
        // Node ber koro
        Node* f=q.front();
        q.pop();

        // Node niye kaj
        cout<<f->val<<endl;
        
        // Child push
        if(f->left)q.push(f->left);
        if(f->right)q.push(f->right);
    }
}

int main(){
    Node* root=input_tree();
    level_order(root);
    return 0;
}