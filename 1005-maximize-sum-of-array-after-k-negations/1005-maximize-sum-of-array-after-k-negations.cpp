class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
           sort(nums.begin(),nums.end());
          int i =0;
          while(i<nums.size()&&nums[i]<0){
            nums[i]=-nums[i];
            i++;
            k--;
            if(k==0)break;
          }
          sort(nums.begin(),nums.end());
          if(k>0&&k%2!=0){
           
                nums[0]=-nums[0];
            
          }
          int ans =0;
          for(int i =0;i<nums.size();i++){
            ans+=nums[i];
          }
          return ans ;
    }
};