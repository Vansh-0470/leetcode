class Solution {
public:
    // median se least ans aaega 
    int minMoves2(vector<int>& nums) {
       sort(nums.begin(),nums.end());
    //    int sum =0;
    //    for(int i =0;i<nums.size();i++){
    //     sum+=nums[i];
    //    } 
    //    int n =nums.size();
    //    int ans =INT_MAX;
    //    for(int i =0;i<nums.size();i++){
    //     int check =nums[i]*n;
    //     int val =abs(sum-check);
    //     ans=min(ans,val);
    //    }
    //    return ans ;
    int n =nums.size();
    int median;
    //n--;
    if(n%2==0&&n!=0){
     median=(nums[n/2]+nums[(n/2)-1])/2;
    }
    else {
        median =nums[(n-1)/2];
    }
    int ans =0;
    for(int i =0;i<n;i++){
     ans+=abs(median-nums[i]);
    }
    return ans ;
    }
};