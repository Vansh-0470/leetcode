class Solution {
public:

   // void subset(vector<int>nums,int count , )
    int help(vector<int>&nums, int target , vector<int>&dp){
        if(target==0){
           return 1;
        }
        if(target<0){
            return 0 ;
        }
        // if(i==nums.size()){
        //     return 0 ;
        // }
        if(dp[target]!=-1){
            return dp[target];
        }
        int ans=0;
        for(int j=0;j<nums.size();j++){
        ans=ans+help(nums,target-nums[j],dp);
        }
    //   int same=  help(nums,target-nums[i],i,dp);
    //   int change =  help(nums,target,i+1,dp);
return dp[target]=ans;
       
    }
    int combinationSum4(vector<int>& nums, int target) {
       vector<int>dp(target+1,-1);
     return   help(nums,target,dp);
      //  return count;
    }
};