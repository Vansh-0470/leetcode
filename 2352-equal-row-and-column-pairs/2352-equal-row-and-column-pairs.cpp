class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {



         int n = grid.size();
        map<vector<int>, int> mp;

        for (int i = 0; i < n; i++) {
            mp[grid[i]]++;
        }

        int ans = 0;

        for (int j = 0; j < n; j++) {
            vector<int> col;

            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }

            ans += mp[col];
        }

        return ans;
        // vector<string>row;
        // vector<string>column;
        // int n =grid.size();
        // for(int i =0;i<n;i++){
        //     string a;
        //     for(int j =0;j<n;j++){
        //        a += to_string(grid[i][j]) + ",";
        //     }
        //     row.push_back(a);
        // }

        //  for(int i =0;i<n;i++){
        //     string a;
        //     for(int j =0;j<n;j++){
        //        a += to_string(grid[j][i]) + ",";
        //     }
        //     column.push_back(a);
        // }

        // int count =0;
        //  for(int i =0;i<n;i++){
        //     for(int j =0;j<n;j++){
        //        if(row[i]==column[j]){
        //         cout<<i<<endl;
        //         cout<<j<<endl;
        //         count++;
        //        }
        //     }
          
        // }
        // return count ;
    }
};