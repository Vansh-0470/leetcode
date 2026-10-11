class Solution {
public: 
     bool match(string &s , string & p , int i , int j ,vector<vector<int>>&dp){
        if(i==s.length()&&j==p.length()){
            return true ;
        }
        if(j==p.length()&&i!=s.length()){
            return false ;
        }
        if(i==s.length()&&j!=p.length()){
             if(p[j]=='*'){
                return match(s,p,i,j+1,dp);
             }
        return false;
        }
   if(dp[i][j]!=-1){
    return dp[i][j];
   }
         if ( p[j] == '*'){
        bool del = match(s, p, i, j +1,dp);
       // bool take = false;

      
         bool   take = match(s, p, i + 1, j,dp);
        

        return dp[i][j]=del || take;
        }
                if(s[i]==p[j]||p[j]=='?'){
            return dp[i][j]=match(s,p,i+1,j+1,dp);
        }
        return dp[i][j]=false ;
    }
    bool isMatch(string s, string p) {
         vector<vector<int>>dp(s.length(),vector<int>(p.length(),-1));
        return match(s,p,0,0,dp);
    }
};