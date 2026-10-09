class Solution {
public:
   // brute force  just go for a combination in dict to get the word 
   // for dp state think wheter remaining string could be formed or not 
    bool unboundedknp(string &s , vector<string>&dict, int i, vector<int>&dp  ){
     
      if(i==s.length()){
             return true ;

      }
      if(dp[i]!=-1){
        return dp[i];
      }
      for(int j =0;j<dict.size();j++){
        if(dict[j].length()+i<=s.length()&&s.substr(i,dict[j].length())==dict[j])
         if(unboundedknp(s,dict , i+dict[j].length(),dp)){
            return dp[i]=true ;
         }
      }
      return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         //bool ans =false ;
         vector<int>dp(s.length(),-1);
      return    unboundedknp(s, wordDict, 0,dp);
        // return ans ;
    }
};