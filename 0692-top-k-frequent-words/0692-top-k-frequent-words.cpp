class Solution {
public:
// approach 1 done with priority queue this is o(nlogk)
// aproach2 can use bucket sort in which we will make vector<vector<string>> and for freq we will add all string that comes at that freq and then will traverse backward and add the string in the ans as soon as size of ans equals k return ans this is o(n)
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>m;
        for(int i =0;i<words.size();i++){
            m[words[i]]++;
        }
        struct compare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first != b.first)
            return a.first > b.first;   // smaller freq has higher priority

        return a.second < b.second;     // greater string has higher priority
    }
};
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare>pq;
        for(auto it:m){
            int freq=it.second;
            string a=it.first;
            pq.push({freq,a});
            if(pq.size()>k)pq.pop();
        }
        vector<string>ans;
      // vector<string>freqcheck;
        //int pre =-1;
        while(!pq.empty()){
          //  if(pre=-1||pre!=pq.top().first){
                   ans.push_back(pq.top().second);
           // }
           
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        //sort(ans.begin(),ans.end());
        return ans ;
    }
};