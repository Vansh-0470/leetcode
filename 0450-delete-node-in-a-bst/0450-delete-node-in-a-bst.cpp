/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<TreeNode*, TreeNode*> search(TreeNode* root, int key,
                                      TreeNode* parent) {
        if (root == NULL)
            return {NULL, NULL};
        if (root->val == key) {
            return {root, parent};
        } else if (root->val > key) {
            return search(root->left, key, root);
        } else {
            return search(root->right, key, root);
        }
        //  return ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        auto it = search(root, key, NULL);
        TreeNode* node = it.first;
        TreeNode* parent = it.second;
        if (node == NULL)
            return root;
// no child
        if (node->left == NULL && node->right == NULL) {

            if (parent == NULL) {
                delete node;
                return NULL;
            }

            if (parent->left == node)
                parent->left = NULL;
            else
                parent->right = NULL;

            delete node;
            return root;
        }
        // for one left child 
        if (node->left != NULL && node->right == NULL) {

            if (parent == NULL) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            if (parent->left == node)
                parent->left = node->left;
            else
                parent->right = node->left;

            delete node;
            return root;
        }
        // for one right child 
        if (node->left == NULL && node->right != NULL) {

            if (parent == NULL) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }

            if (parent->left == node)
                parent->left = node->right;
            else
                parent->right = node->right;

            delete node;
            return root;
        }
        // two child 
        TreeNode *temp =node->right;
        TreeNode * pre =NULL;
        while(temp->left!=NULL){
            pre=temp;
            temp=temp->left;
        }
        node->val=temp->val;
        if(pre==NULL){
            node->right=temp->right;
        }
        else {
 pre->left=temp->right;
        }
       
        delete temp ;
        return root ;

        // return node;
    }
};