#include<bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<int>ans;
    void post_order(TreeNode* root){
        if(root == NULL) return ;
        ans.push_back(root->val);
        post_order(root->left);
        post_order(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        post_order(root);
        return ans;
    }
};