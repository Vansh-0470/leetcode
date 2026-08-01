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

   unordered_map<int, int>m;
  //  unordered_map<int, int>m1;
    int lefthalf ;
   TreeNode * build (vector<int>& preorder, vector<int>& postorder,int left , int right , int &preidx){
   // if(preidx>=preorder.size())return NULL;
    if(left>right)return NULL;
    TreeNode * root=new TreeNode(preorder[preidx]);
  
    preidx++;
      if (left == right)
    return root; 
  int postidx=m[preorder[preidx]];

  
    root->left=build(preorder , postorder ,left ,postidx,preidx);
    root->right=build(preorder , postorder , postidx+1,right-1,preidx );
    return root;
   }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i =0;i<postorder.size();i++){
            m[postorder[i]]=i;
        }
        //  for(int i =0;i<postorder.size();i++){
        //     m1[preorder[i]]=i;
        // }
        int preidx =0;
  TreeNode * root =build (preorder , postorder , 0 , postorder.size()-1,preidx);
  return root ;
    }
};