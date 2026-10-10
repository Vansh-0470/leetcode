class Solution {
public:
// main concept is to look for * at next position before char match 
    bool match(string &s , string & p , int i , int j ,vector<vector<int>>&dp){
        if(i==s.length()&&j==p.length()){
            return true ;
        }
        if(j==p.length()&&i!=s.length()){
            return false ;
        }
        if(i==s.length()&&j!=p.length()){
            if (j + 1 < p.length() && p[j + 1] == '*') {
            return match(s, p, i, j + 2,dp);
        }
        return false;
        }
   if(dp[i][j]!=-1){
    return dp[i][j];
   }
         if (j + 1 < p.length() && p[j + 1] == '*'){
        bool del = match(s, p, i, j + 2,dp);
        bool take = false;

        if (s[i] == p[j] || p[j] == '.') {
            take = match(s, p, i + 1, j,dp);
        }

        return dp[i][j]=del || take;
        }
                if(s[i]==p[j]||p[j]=='.'){
            return dp[i][j]=match(s,p,i+1,j+1,dp);
        }
        return dp[i][j]=false ;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length(),vector<int>(p.length(),-1));
        return match(s,p,0,0,dp);
    }
};