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
     void post(TreeNode * root, int &sum){
        if(root==NULL)return ;
        post(root->right,sum);
         root->val=root->val+sum;
        sum=root->val;
        post(root->left,sum);
       
     }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        post(root,sum);
        return root ;
    }
};