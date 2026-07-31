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
unordered_map<int,int>m;
    TreeNode * build (vector<int>& inorder, vector<int>& postorder,int left , int right , int &postidx){
        if(left>right)
        return NULL;
        TreeNode * root =new TreeNode(postorder[postidx]);
        postidx--;
        int inorderidx=m[root->val];
        root->right=build(inorder , postorder , inorderidx+1,right,postidx);
        root->left=build(inorder , postorder , left , inorderidx-1,postidx);
        
        return root ;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for(int i =0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int postidx=postorder.size()-1;
       TreeNode * root =build(inorder , postorder , 0,inorder.size()-1,postidx);
       return root ;
    }
};