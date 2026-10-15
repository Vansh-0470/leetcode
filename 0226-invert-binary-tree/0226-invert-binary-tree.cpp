/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode * root){
        if(root==NULL)return ;
        if(root->left!=NULL&&root->right!=NULL){

            swap(root->left,root->right);
        }
        else if (root->left==NULL&&root->right!=NULL){
            root->left=root->right;
            root->right=NULL;
        }
        else if(root->right==NULL&&root->left!=NULL) {
            root->right=root->left;
            root->left=NULL;
        }
        traverse(root->left);
        traverse(root->right);
        
        
    }
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root ;
    }
};