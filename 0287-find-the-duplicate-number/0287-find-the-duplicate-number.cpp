class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int  n=nums.size();
        long long actual=0;
       for(int i =0;i<n;i++){
           while(nums[i]!=i+1){
            int check=nums[i];
            swap(nums[i],nums[nums[i]-1]);
            if(check==nums[i]){
                return check ;
            }
           }
       }
       return 0;
   // return actual-effective ;
    }
};