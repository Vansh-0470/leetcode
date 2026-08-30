class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& station) {
        int n =station.size();
        int x =n;
        priority_queue<pair<int,int>>q;
        int ans =0;
        int pre=0;
        int i =0;
        int fuelused=0;
        while(x>=0){
            if((startFuel+pre)>=target)return ans ;
            while(i>=0&&i<n&&(startFuel+pre)>=station[i][0]){
                q.push({station[i][1],station[i][0]});
                i++;
            }
            if(!q.empty()){
               fuelused=q.top().second-pre;
            // target=target-q.top().second;
             pre=q.top().second;
             ans++;
             startFuel=startFuel+q.top().first-fuelused;
             q.pop();
            }
            else {
              break;
            }
           x--;
        }
        if(startFuel<target)return -1;
        return ans;
    }
};