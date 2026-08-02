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
     TreeNode * build (vector<int>&preorder,vector<int>&inorder, int left , int right , int &preidx){
        if(left>right)return NULL;
        TreeNode * root =new TreeNode (preorder[preidx]);
        preidx++;
       //  if(preidx>=preorder.size())return root ;
        int idx=m[root->val];
        root->left=build(preorder, inorder , left , idx-1,preidx);
        root->right=build(preorder, inorder, idx+1,right , preidx);
        return root ;
     }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
         vector<int>help;
       
       for(int i =0;i<preorder.size();i++){
       // m[preorder[i]]=i;
        help.push_back(preorder[i]);
       }
      // here help is preorder 
      // preorder is inorder 
       sort(preorder.begin(),preorder.end());
        for(int i =0;i<preorder.size();i++){
        m[preorder[i]]=i;
        //help.push_back(preorder[i]);
       }
       int a=0;
     return build (help,preorder , 0,preorder.size()-1,a);
    }
};