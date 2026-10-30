// class Solution {
// public: 
//     int sub(vector<int>&nums , int i , vector<vector<int>>&dp, int dif, int prefix){
//         if(i==nums.size()){
//             return 0;
//         }
//         if(dp[i][prefix+1]!=-1){
//             return dp[i][prefix+1];
//         }
//         int ans =0;
//         int take =0;
//         int notTake=0;
//         if(prefix==-1||dif==INT_MAX||nums[i]-nums[prefix]==dif){
//             notTake=sub(nums,i+1,dp,dif,prefix);
//             if(prefix!=-1&&dif==INT_MAX){
//                 dif=nums[i]-nums[prefix];
//             }
//             //cout<<dif<<endl;
//              take =1+sub(nums,i+1,dp,dif,i);
             
//             //ans=
//         }
//        else {
//              notTake=sub(nums,i+1,dp,dif,prefix);
//        }
        
//         return dp[i][prefix+1]=max(ans,max(notTake,take));
//     }
//     int longestArithSeqLength(vector<int>& nums) {
//         vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
//         return sub(nums,0,dp,INT_MAX,-1);
//     }
// };





// class Solution {
// public:
//     int sub(vector<int>& nums, int i, vector<vector<vector<int>>>& dp,
//             int dif, int prefix) {
//         if (i == nums.size()) {
//             return 0;
//         }

//         int d = (dif == INT_MAX) ? 20001 : dif + 10000;

//         if (dp[i][prefix+1][d] != -1) {
//             return dp[i][prefix+1][d];
//         }

//         int take = 0;
//         int notTake = 0;

//         notTake = sub(nums, i + 1, dp, dif, prefix);

//         if (prefix == -1 || dif == INT_MAX ||
//             nums[i] - prefix == dif) {
//             if (prefix != -1 && dif == INT_MAX) {
//                 dif = nums[i] - prefix;
//             }

//             take = 1 + sub(nums, i + 1, dp, dif, nums[i]);
//         }

//         d = (dif == INT_MAX) ? 20001 : dif + 10000;

//         return dp[i][prefix + 1][d] = max(take, notTake);
//     }

//     int longestArithSeqLength(vector<int>& nums) {
//         int n = nums.size();

//         vector<vector<vector<int>>> dp(
//             n, vector<vector<int>>(
//                 502, vector<int>(20002, -1)
//             )
//         );

//         return sub(nums, 0, dp, INT_MAX, -1);
//     }
// };


class Solution {
public:
    int sub(vector<int>& nums, int i, int dif,
            vector<unordered_map<int, int>>& dp) {
        if (dp[i].count(dif)) {
            return dp[i][dif];
        }

        int ans = 0;

        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] - nums[i] == dif) {
                ans = max(ans, 1 + sub(nums, j, dif, dp));
            }
        }

        return dp[i][dif] = ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        vector<unordered_map<int, int>> dp(n);
        int ans = 2;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dif = nums[j] - nums[i];
                ans = max(ans, 2 + sub(nums, j, dif, dp));
            }
        }

        return ans;
    }
};