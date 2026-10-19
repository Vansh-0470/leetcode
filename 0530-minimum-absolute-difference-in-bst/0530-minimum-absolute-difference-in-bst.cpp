// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public: 
//     void get(TreeNode * root , int &mini, int leftmax,int rightmin){
//         if(root==NULL){
//             return  ;
//         }
//         get(root->left,mini, max_val,min_val);
//     //      int leftdif=INT_MAX ;
//     //     int rightdif=INT_MAX;
//     //     if(root->left!=NULL){
//     //  leftdif=root->val-root->left->val;
//     //     }
//     //     if(root->right!=NULL){
//     //         rightdif=root->right->val-root->val;
//     //     }
        
       
//         mini=min(mini,min(root->val-min_val,root->val-max_val));
//         //inorder.push_back(root->val);
//         get(root->right,mini,root->right,);
//     }
//     int getMinimumDifference(TreeNode* root) {
//         vector<int>inorder;
//         get(root,inorder);
//         int mini=INT_MAX;
//         for(int i =0;i<inorder.size()-1;i++){
//        mini=min(mini,(inorder[i+1]-inorder[i]));
//         }
//         return mini;
//     }
// };
 // 1st approach can be done by using inorder vector 
 // 2nd approach can maintain a pre in inorder traversal 
 // 3rd approach can be done by using morris inorder traversel
class Solution {
public:
    void get(TreeNode* root, TreeNode*& prev, int& mini) {
        if (root == NULL)
            return;

        get(root->left, prev, mini);

        if (prev != NULL)
            mini = min(mini, root->val - prev->val);

        prev = root;

        get(root->right, prev, mini);
    }

    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = NULL;
        int mini = INT_MAX;

        get(root, prev, mini);

        return mini;
    }
};