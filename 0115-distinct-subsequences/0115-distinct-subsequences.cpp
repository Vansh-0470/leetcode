class Solution {
public:
// sequence doesn't always means look for lcs 
    int check(string & s , string & t  , int i , int j , vector<vector<int>>&dp ){
         if(j==t.length()){
          return 1;
        }
        if(i==s.length()){
            return 0 ;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(t[j]==s[i]){
      dp[i][j]=(check(s, t,i+1,j+1,dp)+check(s,t,i+1,j,dp));   
        }
        else {
         dp[i][j]= check(s,t,i+1,j,dp); 
        }
      return dp[i][j]; 
      
    }
    int numDistinct(string s, string t) {
       int m =s.length();
       int n =t.length();
      // int count =0;
       vector<vector<int>>dp(m,vector<int>(n,-1));
      return  check(s,t,0,0,dp);

    }
};