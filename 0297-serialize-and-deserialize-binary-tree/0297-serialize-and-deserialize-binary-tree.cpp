/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "[]";
        }
       string ans ;
       ans+="[";
       queue<TreeNode*>q;
       q.push(root);
     
       while(!q.empty()){
    TreeNode* node = q.front();
    q.pop();

    if(node){
        ans += to_string(node->val) + ",";
        q.push(node->left);
        q.push(node->right);
    }else{
        ans += "null,";
    }
}
        
        
       ans.pop_back();
       ans+="]";
       return ans ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==2){
            return NULL;
        }
        queue<TreeNode*>q;
        int i =1;int a =0;string help;
        while(i < data.size() && data[i] != ',' && data[i] != ']'){
         help.push_back(data[i]);
         i++;
        }
       if (i < data.size() && data[i] == ',')
    i++;
        a=stoi(help);
        TreeNode * root=new TreeNode(a);
        q.push(root);
        while(!q.empty()){
            TreeNode * node =q.front();
            q.pop();
            string left ;
            string right ;
            int l ;
            int r ;
        while(i<data.size()&&data[i]!=','&&data[i]!=']'){
         left.push_back(data[i]);
         i++;
        }
       if (i < data.size() && data[i] == ',')
    i++;
        if(left=="null"){
        node->left=NULL;
        }
        else {
          //  if(left=="")break;
            l=stoi(left);
            node->left=new TreeNode(l);
            q.push(node->left);
        }
        if (i >= data.size() || data[i] == ']')
    break;
        while(i<data.size()&&data[i]!=','&&data[i]!=']'){
         right.push_back(data[i]);
         i++;
        }
       if (i < data.size() && data[i] == ',')
    i++;
          if(right=="null"){
        node->right=NULL;
        }
        else {
            // if(right=="")break;
            r=stoi(right);
            node->right=new TreeNode(r);
            q.push(node->right);
        }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));