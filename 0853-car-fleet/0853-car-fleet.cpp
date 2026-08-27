class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> combine;
        for (int i = 0; i < speed.size(); i++) {
            combine.push_back({position[i], speed[i]});
        }
 sort(combine.begin(),combine.end(),greater<pair<int,int>>());
     vector<double>time;
     for(int i =0;i<speed.size();i++){
        time.push_back((double)(target-combine[i].first)/combine[i].second);
     }
    //    for(int i =0;i<speed.size();i++){
    //    cout<<time[i]<<" ";
    //  }
     stack<double>fleet;
     for(int i =0;i<speed.size();i++){
       
               if (fleet.empty() || time[i] > fleet.top()) {
               fleet.push(time[i]);
           }
          
     }
     int ans =fleet.size();
     return ans ;
    }
};


