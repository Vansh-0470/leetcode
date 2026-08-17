// to be done in o(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return 1 ;
       sort(nums.begin(),nums.end());
       int ans =1;int count =1;
       for(int i =0;i<nums.size()-1;i++){
        if(nums[i+1]==nums[i]){
        continue ;
        }
         if(nums[i+1]-nums[i]==1){
            count++;
           
         }
         else {
            count =1;
         }
         ans=max(ans,count);
       } 
       return ans ;                
    }
};