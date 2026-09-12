// formula to be remembered;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            vector<int> row;
            long long val = 1;

            for (int j = 0; j <= i; j++) {
                row.push_back(val);
                val = val * (i - j) / (j + 1);
            }

            ans.push_back(row);
        }

        return ans;
    }
};