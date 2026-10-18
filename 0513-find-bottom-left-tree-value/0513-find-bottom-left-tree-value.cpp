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
    void traverse(TreeNode * root , int height, int &maxi, int &ans){
        if(root==NULL)return ;
        if(height>maxi){
            maxi=height ;
            ans=root->val;
        }
        traverse(root->left, height+1,maxi,ans);
        traverse(root->right,height+1,maxi,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
       int maxi=-1;
       int height =0;
       int ans =-1;
       traverse(root,height,maxi,ans);
       return ans ; 
    }
};