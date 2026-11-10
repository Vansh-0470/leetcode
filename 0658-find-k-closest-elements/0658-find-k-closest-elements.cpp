class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>ans;
        for(int i =0;i<arr.size();i++){
            ans.push_back({abs(x-arr[i]),arr[i]});
        }
        sort(ans.begin(),ans.end());
        vector<int>help;
        for(int i =0;i<k;i++){
            help.push_back(ans[i].second);
        }
        sort(help.begin(),help.end());
        return help;
    }
};