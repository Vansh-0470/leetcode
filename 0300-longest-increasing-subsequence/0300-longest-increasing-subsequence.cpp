class Solution {
public: 
// it depends on both idx position and the prefix element 

    int subseq(vector<int>&nums, int prefix , vector<vector<int>>&dp, int i ){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prefix+1]!=-1){
            return dp[i][prefix+1];
        }
        if(prefix==-1||nums[i]>nums[prefix]){
            dp[i][prefix+1]=max(1+subseq(nums,i,dp,i+1),subseq(nums,prefix , dp,i+1));
        }
        else {
            dp[i][prefix+1]=subseq(nums,prefix , dp,i+1);
        }
        return dp[i][prefix+1];
    }
    int lengthOfLIS(vector<int>& nums) {

      vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
      return   subseq(nums,-1,dp,0);
    }
};