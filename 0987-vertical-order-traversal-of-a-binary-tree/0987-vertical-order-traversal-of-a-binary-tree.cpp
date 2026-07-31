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
    using pii = pair<pair<int,int>,int>;
using minHeap = priority_queue<pii, vector<pii>, greater<pii>>;
public:

    void traverse(TreeNode * root ,minHeap& pq , int j, int i ){
        if(root==NULL){
            return ;
        }
        pq.push({{j,i},root->val});
        traverse(root->left,pq,j-1,i+1);
        traverse(root->right,pq,j+1,i+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root==NULL){
            return ans ;
        }
           minHeap pq ;
           traverse(root,pq,0,0);
           int pre =INT_MIN;
           vector<int>help;
          while(!pq.empty()){
            int j =pq.top().first.first;
            int i =pq.top().first.first;
            int node =pq.top().second;
            pq.pop();
            if(pre!=j&&pre!=INT_MIN){
              ans.push_back(help);
              help.clear();
            }
            help.push_back(node);
            pre=j;
          }
        ans.push_back(help);
return ans ;
    }
};