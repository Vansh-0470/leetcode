class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n =nums.size();
      int minidx=-1;
      int maxidx=-1;
      int mini=INT_MAX;
      int maxi=INT_MIN;
      for(int i =0;i<nums.size();i++){
        if(mini>nums[i]){
            mini=nums[i];
            minidx=i;
        }
        if(maxi<nums[i]){
            maxi=nums[i];
            maxidx=i;
        }
      }
        int left=max(minidx+1,maxidx+1);
        int right=max(n-minidx,n-maxidx);
        int both;
        if(maxidx>minidx){
            both =minidx+1+n-maxidx;
        }
        else {
            both=maxidx+1+n-minidx;
        }
        return min(both,min(right,left));
    }
};