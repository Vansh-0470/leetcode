class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2){
        return abs(v1[0]-v1[1]) > abs(v2[0] - v2[1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cmp);
        int ans=0, aCount = costs.size()/2, bCount = costs.size()/2;
        int k=0;
        for(;k<costs.size();k++){
            int i = costs[k][0];
            int j = costs[k][1];
            if(i>j){
                ans+= j;
                bCount--;
            }else{
                ans += i;
                aCount--;
            }

            if(aCount==0 || bCount==0)  break;
        }
        k++;
        while(k<costs.size() && aCount>0){
            ans += costs[k][0];
            aCount--;
            k++;
        }

        while(k<costs.size() && bCount>0){
            ans += costs[k][1];
            bCount--;
            k++;
        }
        return ans;
    }
};