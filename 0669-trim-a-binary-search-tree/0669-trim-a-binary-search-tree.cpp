class Solution {
public:
    void help(TreeNode*& root, int low, int high, TreeNode* parent) {
        if (root == NULL)
            return;

        if (root->val > high) {
            if (parent == NULL) {
            
                root = root->left;
            
            }
            else {
             

                if (parent->right == root) {
                    parent->right = root->left;
                    root = parent->right;
                }
                else if (parent->left == root) {
                    parent->left = root->left;
                    root = parent->left;
                }

               

              
            }
         help(root, low, high, NULL);
                return;
        }

        else if (root->val < low) {
            if (parent == NULL) {
             
                root = root->right;
             

               
            }
            else {
              

                if (parent->right == root) {
                    parent->right = root->right;
                    root = parent->right;
                }
                else if (parent->left == root) {
                    parent->left = root->right;
                    root = parent->left;
                }

            
            }
             help(root, low, high, NULL);
                return;
        }

        help(root->left, low, high, root);
        help(root->right, low, high, root);
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        help(root, low, high, NULL);
        return root;
    }
};