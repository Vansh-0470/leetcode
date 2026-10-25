class Solution {
public:
    // when word2 complete then delete the remaing char of word1
    // when word1 complete then insert the remaining char of word2 

    int check(string& word1, string& word2, int& ans, int i, int j, vector<vector<int>>&dp) {
        if (j == word2.length()) {
           
                return (word1.length() - i);
          
        }
        if (i == word1.length()) {
           
                return (word2.length() - j);
           
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if (word1[i] == word2[j]) {
            dp[i][j]= check(word1, word2, ans, i + 1, j + 1,dp);
        } else {
            dp[i][j]= min(1+check(word1, word2, ans, i + 1, j,dp),
                       min(1+check(word1, word2, ans, i, j + 1,dp),
                          1+ check(word1, word2, ans, i + 1,
                                 j + 1,dp))); // delete
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        //int count = 0;
        int ans = INT_MAX;
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        return check(word1, word2, ans, 0, 0,dp);
        //  return ans ;
    }
};