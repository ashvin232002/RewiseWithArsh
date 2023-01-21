#include<bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
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
    unordered_map<TreeNode*,int>mp;
    int recursion(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(mp.find(root)!=mp.end()){
            return mp[root];
        }
        int include = root->val;
        if(root->left!=NULL){
            include+=recursion(root->left->left)+recursion(root->left->right);
        }
        if(root->right!=NULL){
            include+=recursion(root->right->left)+recursion(root->right->right);
        }

        int exclude = recursion(root->left)+recursion(root->right);
        return mp[root]=max(include,exclude);
    }
    int rob(TreeNode* root) {
        return recursion(root);
    }
};