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
    vector<int> in;
    int idx = 0;
    void inorder(TreeNode* node){
        if(!node) return;
        inorder(node->left);
        in.push_back(node->val);
        inorder(node->right);
    }
    void inorder1(TreeNode* node){
        if(!node) return;
        inorder1(node->left);
        if(node->val != in[idx]){
            node->val = in[idx];
        }
        idx++;
        inorder1(node->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root) return;
        inorder(root);
        sort(in.begin(), in.end());
        inorder1(root);
    }
};