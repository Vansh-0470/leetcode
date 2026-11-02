//class Solution {
//public:
  //  int maxSubarraySumCircular(vector<int>& nums) {
    //    int sum=0;
    //    int pre =-1;
     //   int n =nums.size();
    //    int maxsum=INT_MIN;
    //    for(int i =0;i<n;i++){
    //     sum+=nums[i];
    //     maxsum=max(maxsum,sum);
    //     if(sum<0){
    //         pre=i;
    //         sum=0;
    //     }
    //    }
    // if(pre==-1){
    //       int check=nums[0]+nums[n-1];
    //       maxsum=max(check,maxsum);
    //     return maxsum;
    // }
    // else {
    //     for(int i =0;i<pre;i++){
    //         sum+=nums[i];
    //         maxsum=max(sum,maxsum);
    //         if(sum<0){
    //             sum=0;
    //         }
    //     }
    // }
  
   class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        int sum = 0;
        int minsum = INT_MAX;
        int maxsum = INT_MIN;
        int maxi = INT_MIN;

        int currMax = 0;
        int currMin = 0;

        for (int i = 0; i < n; i++) {
            total += nums[i];
            maxi = max(maxi, nums[i]);

            currMax += nums[i];
            maxsum = max(maxsum, currMax);

            if (currMax < 0) {
                currMax = 0;
            }

            currMin += nums[i];
            minsum = min(minsum, currMin);

            if (currMin > 0) {
                currMin = 0;
            }
        }

        if (maxi < 0) {
            return maxi;
        }

        return max(maxsum, total - minsum);
    }
};
