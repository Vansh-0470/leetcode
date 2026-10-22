class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> dp;

    int solve(int n, int k, int target, int count, int sum) {
        if (count == n)
            return sum == target;

        if (sum > target)
            return 0;

        if (dp[count][sum] != -1)
            return dp[count][sum];

        long long ans = 0;

        for (int i = 1; i <= k; i++) {
            if (sum + i <= target) {
                ans = (ans + solve(n, k, target, count + 1, sum + i)) % mod;
            }
        }

        return dp[count][sum] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        dp.assign(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target, 0, 0);
    }
};