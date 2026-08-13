
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n =nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        if(nums.size()==1)return 1 ;
        int i =0;int j =1;
        int ans=INT_MIN;
        int count =1;
        int reset=k;
        long long  sum=nums[i];
        while(i<n&&j<n){
             sum+=nums[j];
             int countidx=j-i+1;
            long long cost = (long long)nums[i] * countidx - sum;
             if(cost<=k){
               // k-=cost;
                ans=max(countidx,ans);
             }
           else {
            while(cost>k){
              
                sum-=nums[i];
                  i++;
                  countidx=j-i+1;
                cost= (long long)nums[i] * countidx - sum;
            }
           }
           j++;
            // int dif=nums[i]-nums[j];
            // if(k>=dif){
            //     k-=dif;
            //     count++;
            //     ans=max(count ,ans);
            //     j++;
            // }
            // else {
            //     i++;
            //     count--;
            //     j=i+1;
            //     count=1;
            //     k=reset;
            // }
        }
        if(ans==INT_MIN)return 1 ;
        return ans ;
    }
};