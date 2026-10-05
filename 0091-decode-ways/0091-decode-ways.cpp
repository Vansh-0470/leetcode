class Solution {
public:
    int help(string &s , int i ,vector<int>&dp){
        if(i==s.length()){
            
            return 1 ;
        }
        
   if(s[i]=='0')return 0;
   if(dp[i]!=-1){
        return dp[i];
   }
      dp[i] = help(s,i+1,dp);
       if (i + 1 < s.length()) {
    int x = (s[i]-'0') * 10 + (s[i+1]-'0');

    if (x >= 10 && x <= 26) {
     dp[i]+=   help(s, i+2,dp);
    }
}
return dp[i];
       }
    
    int numDecodings(string s) {
       if(s[0]=='0')return 0;
       int count =0;
       vector<int>dp(s.length(),-1);
     return   help(s,0,dp );
       //return count ;
    }
};