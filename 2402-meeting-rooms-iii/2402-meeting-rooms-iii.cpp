class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int>rooms(n,0);
      priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<pair<long long ,int>>>q;
      for(int i =0;i<n;i++){
        q.push({0,i});
      } 
      int size=meetings.size();
      sort(meetings.begin(),meetings.end());
      for(int i =0;i<size;i++){
        int time =meetings[i][0];
        long long  duration=meetings[i][1]-meetings[i][0];
        // if(q.top().first<=time){
        //     int roomno=q.top().second;
        //     int freetime=q.top().first;
        //     rooms[roomno]++;
        //     q.pop();
        //     freetime=time+duration;
        //     q.push({freetime,roomno});
        // }
        int mini=INT_MAX;
       // int freetime
        vector<pair<long long ,int>>help;
        while(!q.empty()){
            if(q.top().first<=time){
               mini=min(mini,q.top().second);
            }
           help.push_back({q.top().first,q.top().second});
           q.pop();
        }
        for(int k=0;k<help.size();k++){
            if(help[k].second!=mini){
         q.push(help[k]);
            }
        }
        if(mini!=INT_MAX){
            q.push({(long long)time+duration,mini});
            rooms[mini]++;
        }
        else {
            int roomno=q.top().second;
            long long freetime=q.top().first;
            rooms[roomno]++;
            q.pop();
            freetime+=duration;
            q.push({(long long)freetime,roomno});
        }
        
      } 
      int maxi=INT_MIN;
      int ans=-1;
      for(int i =0;i<n;i++){
    if(rooms[i]>maxi){
        maxi=rooms[i];
        ans=i;
    }
      }  
      return ans ; 
    }
};