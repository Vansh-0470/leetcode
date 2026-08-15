class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int count =0;
       int sum =0;
       unordered_map<int,int>m;
       m[0]=1;
       for(int i =0;i<nums.size();i++){
        sum+=nums[i];
        int need = sum-k;
        if(m.find(need)!=m.end())count+=m[need];
        m[sum]++;
       }
       return count;
    }
};