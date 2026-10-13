// class Solution {
// public:
//     int knap(int &n,int add , int prod, int i, int &maxprod){
//         if(i==n||add==n){
//             maxprod=max(prod,maxprod);
//             return maxprod;
//         }
//         // if(dp[add][i]!=-1){
//         //     return dp[add][i];
//         // }
//        int local;
//         if(add+i<=n){
//          local=max(knap(n,add+i,prod*i,i,maxprod),knap(n,add,prod,i+1,maxprod));
//         }
//         else {
//             local=knap(n,add,prod,i+1,maxprod);
//         }
//     return local;
//     }
//     int integerBreak(int n) {
//         int m=1;
//         // int dp[59][59];
//         // memset(dp,-1,sizeof(dp));
//          return knap(n,0,1,1,m);
//     }
// };

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 1) return 1;

        if (dp[n] != -1) return dp[n];

        int ans = 0;

        for (int i = 1; i < n; i++) {
            ans = max(ans, i * max(n - i, solve(n - i, dp)));
        }

        return dp[n] = ans;
    }

    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

