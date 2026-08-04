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
   TreeNode* search(TreeNode* root, int key) {
    if (root == NULL) return NULL;
    if (root->val == key) return root;
    TreeNode* left = search(root->left, key);
    if (left != NULL) return left;
    return search(root->right, key);
}
    void check(TreeNode * root , vector<int>&ans){
        if(root==NULL)return ;
        // if(root->val>maxi){
        //     // pre->val=root->val;
        //     // root->val=maxi;
        //     swap(pre->val,root->val);
        //     return ;
        // }
        //   if(root->val<mini){
        //     // pre->val=root->val;
        //     // root->val=mini;
        //     swap(pre->val,root->val);
        //     return ;
        // }
        check(root->left,ans);
        ans.push_back(root->val);
        check(root->right,ans);
    }
    void recoverTree(TreeNode* root) {
        vector<int> ans;
    check(root, ans);

    vector<int> fuck = ans;
    sort(fuck.begin(), fuck.end());

    int x = -1, y = -1;

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] != fuck[i]) {
            if (x == -1)
                x = ans[i];
            else
                y = ans[i];
        }
    }

    TreeNode* helpi = search(root, x);
    TreeNode* helpj = search(root, y);

    swap(helpi->val, helpj->val);
    }
};