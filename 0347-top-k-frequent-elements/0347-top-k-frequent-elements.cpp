// could also be done using decreasig order map but it still takes nlogn so same thing
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       priority_queue<pair<int,int>>pq;
       unordered_map<int,int>m;
       vector<int>ans;
       for(int i =0;i<nums.size();i++){
           m[nums[i]]++;
       } 
       for(auto it :m){
        pq.push({it.second,it.first});
       }
       for(int i =0;i<k;i++){
        int a=pq.top().second;
        ans.push_back(a);
        pq.pop();
       }
       return ans ;
    }
};