class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0){
            return 0;
        }
       sort(points.begin(), points.end(), [](auto &a, auto &b) {
    return a[1] < b[1];
});
        int count=1;
        int x=points[0][1];
       for(int i =1;i<points.size();i++){
        if(points[i][0]<=x&&x<=points[i][1]){
            continue;
        }
        else {
            count++;
            x=points[i][1];
        }
       }
       return count;
    }
};