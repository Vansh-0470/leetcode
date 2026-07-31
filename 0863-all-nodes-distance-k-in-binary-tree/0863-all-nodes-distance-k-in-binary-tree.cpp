/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     void graph(TreeNode * root , vector<vector<int>>&adj){
        if (root==NULL)return ;
        if(root->left!=NULL){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
         if(root->right!=NULL){
            adj[root->val].push_back(root->right->val);
             adj[root->right->val].push_back(root->val);
        }
        graph(root->left,adj);
        graph(root->right,adj);

     }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      vector<vector<int>>adj(501);
      graph(root,adj);
      vector<int> ans;
      queue<pair<int,int>>q;
      q.push({target->val,0});
      vector<bool>vis(501,false);
      vis[target->val]=true;
      while(!q.empty()){
        int node =q.front().first;
        int time =q.front().second;
        if(time==k){
            ans.push_back(node);
        }
        q.pop();
        if(time>k){
            continue ;
        }
        for(auto it :adj[node]){
            if(!vis[it]){
 vis[it]=true ;
           q.push({it,time+1});
            }
           
        }
      }
      
      return ans ;
    }
};