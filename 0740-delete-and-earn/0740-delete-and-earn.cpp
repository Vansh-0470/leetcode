class Solution {
public:
    int earn(vector<int>&nums,int i ,vector<int>&dp){
          if(i==nums.size()){
            return 0;
          }
          if(dp[i]!=-1){
            return dp[i];
          }
          int sum=nums[i];
           int j =i;
          while(j<nums.size()-1&&nums[j+1]==nums[i]){
            sum+=nums[i];
            j++;
          }
         int k =j;
          while(k<nums.size()-1&&nums[k+1]==1+nums[i]){
               k++;
          }
          int take =sum+earn(nums,k+1,dp);
          int notTake=earn(nums,j+1,dp);
          
          return dp[i]=max(take,notTake);

    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size()+1,-1);
        return earn(nums,0,dp);
    }
};