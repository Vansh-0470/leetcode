class Solution {
public:
    string reorganizeString(string s) {
        vector<int>help(26,0);
        for(int i =0;i<s.length();i++){
          help[s[i]-'a']++;
        }
        priority_queue<pair<int,int>>q;

        for(int i =0;i<26;i++){
      if(help[i]!=0){
        q.push({help[i],i});
      }
        }
        string ans ;
        while(!q.empty()){
            vector<pair<int,int>>check;
            int n =1;
            while(!q.empty()){
                int idx =q.top().second;
                int b =q.top().first;
                ans.push_back(idx+'a');
                n--;
                b--;
                if(b!=0){
                 check.push_back({b,idx});
                }
                q.pop();
                if(n==-1)break;
            }
            for(int i =0;i<check.size();i++){
                q.push(check[i]);
            }
        }
        for(int i =0;i<ans.length()-1;i++){
         if(ans[i+1]==ans[i])return "";
        }
        return ans ;
    }
};