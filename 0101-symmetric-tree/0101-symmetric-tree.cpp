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
     bool help(TreeNode * p , TreeNode * q){
        if(p==NULL&&q==NULL)return true ;
        if(p==NULL||q==NULL)return false ;
        if(p->val!=q->val)return false ;
        bool left =help(p->left,q->right);
        bool right =help(p->right , q->left);
           return left&&right;
     }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true ;
        if(root->left!=NULL&&root->right!=NULL){
            return help(root->left,root->right);
        }
        else if (root->left==NULL&&root->right==NULL) {
            return true ; ;
        }
        else {
            return false ;
        }
    }
};