class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<long long ,pair<int,int>>>pq;
        for(int i =0;i<points.size();i++){
            int a =points[i][0];
            int b =points[i][1];
            long long  distance=(a*a+b*b);
            pq.push({distance,{a,b}});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            vector<int>help;
            help.push_back(pq.top().second.first);
            help.push_back(pq.top().second.second);
            ans.push_back(help);
            pq.pop();
        }
        return ans ;
    }
};