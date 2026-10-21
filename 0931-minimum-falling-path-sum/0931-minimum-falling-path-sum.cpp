class Solution {
public:
    int sum(vector<vector<int>>& matrix, int i , int j,vector<vector<int>>&dp ){
        if(i==matrix.size()||j==matrix[0].size()||j==-1){
            return INT_MAX;
        }

        if(i==matrix.size()-1&&j<=matrix[0].size()-1){
   return dp[i][j]= matrix[i][j];
        }
        if(dp[i][j]!=INT_MIN){
            return dp[i][j];
        }
        return dp[i][j]=matrix[i][j]+min(sum(matrix,i+1,j,dp),min(sum(matrix,i+1,j-1,dp),sum(matrix,i+1,j+1,dp)));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini =INT_MAX;
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,INT_MIN));
        for(int i =0;i<matrix[0].size();i++){
            mini=min(mini,sum(matrix,0,i,dp));
        }
        return mini ;
    }
};