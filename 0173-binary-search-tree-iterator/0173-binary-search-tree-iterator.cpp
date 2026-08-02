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
class BSTIterator {
public:
   int pointer =-1;
   vector<int>inorder;
    BSTIterator(TreeNode* root) {
       queue<TreeNode * >q;
       q.push(root);
       inorder.push_back(root->val);
       while(!q.empty()){
        TreeNode * node =q.front();
        q.pop();
        if(node->left!=NULL){
            q.push(node->left);
            inorder.push_back(node->left->val);
        }
      
         if(node->right!=NULL){
            q.push(node->right);
            inorder.push_back(node->right->val);
        }
       
       } 
       sort(inorder.begin(),inorder.end());
    }
    
    int next() {
     
     pointer =pointer+1;
     return inorder[pointer];   
    }
    
    bool hasNext() {
        if(pointer+1<inorder.size())return true ;
        else return false ;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */