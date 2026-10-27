class Solution {
public:  
    // void check(int n , int i , int mini , int & ans, int sum, vector<vector<int>>dp ){
    //     if(sum==n){
    //         ans=min(mini,ans);
    //         return;
    //     }
    //     if(sum>n||i>sqrt(n)){
    //         return ;
    //     }        
    //     check(n ,i , mini+1,ans , sum+i*i );
    //     check(n , i+1, mini,ans,sum);
    // }
    //     int check(int n , int i ,vector<vector<long long>>&dp, long long sum){
    //     if(sum==n){
    //         return 0 ;
    //     }
    //     if(sum>n||i>sqrt(n)){
    //         return INT_MAX;
    //     }
    //     if(dp[i][sum]!=-1){
    //         return dp[i][sum];
    //     }
    //     long long take =(long long)1+check(n,i,dp,sum+i*i);
    //     long long notake=check(n,i+1,dp,sum);
    //     return dp[i][sum]=min(take,notake);
    // }  
      int check(int n , int i  ,vector<long long>&dp){
        if(n==0){
            return 0 ;
        }
        if(n<0||i>sqrt(n)){
            return INT_MAX;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        long long take =(long long)1+check(n-i*i,i,dp);
        long long notake=check(n,i+1,dp);
        return dp[n]=min(take,notake);
    }    
    int numSquares(int n) {
        vector<long long >dp(n+1,-1);
       // int ans =INT_MAX;
       return check(n,1,dp);
       // return ans ;
    }    
};       