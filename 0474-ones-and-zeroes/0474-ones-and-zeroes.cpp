class Solution {
public:
    // will need a 3d dp for this 
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
       vector<vector<vector<int>>> dp(size + 1,vector<vector<int>>(m + 1,vector<int>(n + 1, 0)));
        for(int i =1;i<size+1;i++){
            int count1=0;
            int count0=0;
            for(int x=0;x<strs[i-1].length();x++){
                if(strs[i-1][x]=='0'){
                    count0++;
                }
                else{
                    count1++;
                }
            }
           for(int j=0;j<m+1;j++){
            for(int k=0;k<n+1;k++){
           
            if(count0<=j&&count1<=k){
                dp[i][j][k]=max(1+dp[i-1][j-count0][k-count1],dp[i-1][j][k]);
            }
            else {
                dp[i][j][k]=dp[i-1][j][k];
            }
            }
           }
        }
        return dp[size][m][n];
    }
};