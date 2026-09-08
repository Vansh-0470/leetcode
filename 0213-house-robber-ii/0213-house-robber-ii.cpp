class Solution {
public:
// got it from the hint divide it into two parts 
// first = 0 to n-2 houses 
// second =1to n-1 houses 

    int help(vector<int>& nums, vector<int>& dp, int n) {
        if (n <= 0) return 0;
        if (dp[n] != -1) return dp[n];

        int robbed = nums[n - 1] + help(nums, dp, n - 2);
        int skipped = help(nums, dp, n - 1);

        return dp[n] = max(robbed, skipped);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        
        vector<int> dp1(n, -1);
        int case1 = help(nums, dp1, n - 1);

       
        vector<int> nums_shifted(nums.begin() + 1, nums.end());
        vector<int> dp2(n, -1);
        int case2 = help(nums_shifted, dp2, n - 1);

        return max(case1, case2);
    }
};