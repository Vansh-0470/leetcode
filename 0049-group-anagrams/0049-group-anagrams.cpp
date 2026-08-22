class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>>ans;
       // if(str.size()==0)return ans;
       // cout<<str.size();
       // cout<<"check";
        vector<string>restore=str;
        for(int i =0;i<str.size();i++){
           sort(str[i].begin(),str[i].end());
        }
      priority_queue<pair<string,int>,
               vector<pair<string,int>>,
               greater<pair<string,int>>> pq;
             for(int i =0;i<str.size();i++){
                pq.push({str[i],i});
        } 
        vector<string >help;
        string pre="A"; 
       while(!pq.empty()){
        // if(pq.top().first==""){
            
        //     ans.push_back(help);
        //     pq.pop();
        // }
       if(pre=="A"||pre==pq.top().first){
        help.push_back(restore[pq.top().second]);
        pre=pq.top().first;
        pq.pop();
       }
       else  {
          ans.push_back(help);
          help.clear();
           help.push_back(restore[pq.top().second]);
           pre=pq.top().first;
           pq.pop();
       }

       }
       if(!help.empty()){
        ans.push_back(help);
       }
        return ans ;
    }
};