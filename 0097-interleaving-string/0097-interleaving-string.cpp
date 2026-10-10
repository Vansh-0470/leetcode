class Solution {
public:
    bool cansplit(string &s1, string &s2, string &s3, int i , int j , int k,vector<vector<int>>&dp ){
        if(i==s1.length()&&j!=s2.length()){
           if(s2.substr(j)==s3.substr(k)){
            return true ;
           } 
           else {
            return false ;
           }
        }
         if(i!=s1.length()&&j==s2.length()){
           if(s1.substr(i)==s3.substr(k)){
            return true ;
           } 
           else {
            return false ;
           }
        }
        if(i==s1.length()&&j==s2.length()&&k==s3.length()){
            return true ;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s3[k]&&s2[j]==s3[k]){
             dp[i][j]= cansplit(s1,s2,s3,i+1,j,k+1,dp)||cansplit(s1,s2,s3,i,j+1,k+1,dp);
        }
        else if (s1[i]==s3[k]){
             dp[i][j]= cansplit(s1,s2,s3,i+1,j,k+1,dp);
        }
        else if(s2[j]==s3[k]) {
             dp[i][j]=cansplit(s1,s2,s3,i,j+1,k+1,dp);
        }
        else {
             dp[i][j]=false ;
        }
    return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.length();
        int len2=s2.length();
        int len3=s3.length();
        if(len1+len2!=len3){
            return false ;
        }
        vector<int>freq(26,0);
        for(int i =0;i<len1;i++){
            freq[s1[i]-'a']++;
        }
         for(int i =0;i<len2;i++){
            freq[s2[i]-'a']++;
        }
         for(int i =0;i<len3;i++){
            freq[s3[i]-'a']--;
        }
       for(int i =0;i<26;i++){
        if(freq[i]!=0){
           // cout<<"hello";
            return false ;
            
        }
       }
       vector<vector<int>>dp(len1,vector<int>(len2,-1));
       return cansplit(s1,s2,s3,0,0,0,dp);
    }
};