class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int first=firstList.size();
        int second =secondList.size();
        int traverse=min(first,second);
        vector<vector<int>>ans;
        int i =0;
        int j =0;
        while(i<first&&j<second){
           int maxi =max(firstList[i][0], secondList[j][0]);
            int mini =min(firstList[i][1], secondList[j][1]);
             if(mini>=maxi){
                vector<int>help;
                help.push_back(maxi);
                help.push_back(mini);
                ans.push_back(help);
             }
             if(firstList[i][1]<secondList[j][1]){
                i++;
             }
             else {
                j++;
             }
        }
        return ans ;
    }
};