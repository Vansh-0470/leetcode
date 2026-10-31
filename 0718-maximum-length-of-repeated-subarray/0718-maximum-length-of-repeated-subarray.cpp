
class Solution {
public:
// can also think of it as lcs 
    int funx(vector<int>& nums1, vector<int>& nums2, int i, int j,
             vector<vector<int>>& dp, int& ans) {
        if (i == nums1.size() || j == nums2.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int take = 0;
      // find the length of subarray from i and j 
        if (nums1[i] == nums2[j]) {
            take = 1 + funx(nums1, nums2, i + 1, j + 1, dp, ans);
            ans = max(ans, take);
        }
       // find subarray with different position 
        funx(nums1, nums2, i + 1, j, dp, ans);
        funx(nums1, nums2, i, j + 1, dp, ans);

        return dp[i][j] = take;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1,
                               vector<int>(nums2.size() + 1, -1));
        int ans = 0;
        funx(nums1, nums2, 0, 0, dp, ans);
        return ans;
    }
};
