class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n =s1.length();
        int m =s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i =1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=(int)s1[i - 1]+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string s;
        string del;
        while(n>0&&m>0){
            if(s1[n-1]==s2[m-1]){
                s.push_back(s1[n-1]);
                n--;
                m--;
            }
            else {
                if(dp[n-1][m]>dp[n][m-1]){
                    del.push_back(s1[n-1]);
                    n--;
                }
                else if(dp[n][m-1]>dp[n-1][m]){
                     del.push_back(s2[m-1]);
                    m--;
                }
                else {
                    if(s1[n-1]>s2[m-1]){
                         del.push_back(s2[m-1]);
                        m--;
                    }
                    else {
                         del.push_back(s1[n-1]);
                        n--;
                    }
                }
            }
           
           
        }
        while(m>0){
             del.push_back(s2[m-1]);
             m--;
        }
        while(n>0){
             del.push_back(s1[n-1]);
             n--;
        }
        //  cout<<del<<endl;
        //  cout<<s;
         int sum =0;
         for (char c : del) {
    sum += int(c);
}
         return sum;
    }
};