class Solution {
public:
    int minMoves(vector<int>& nums) {
        int  n =nums.size();
        if(n==1){
            return 0;
        }
        long long  total=0;
        //sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        for(int i =0;i<n;i++){
            total+=nums[i];
          mini=min(mini,nums[i]);
           
        }
        //cout<<mini;
        int ans =0;
        for(int i=0;i<n;i++){
            ans+=abs(nums[i]-mini);
        }
    //    while(total!=(nums[mini]*n)){
    //          nums[mini]++;
    //          ans++;
    //          total=0;
    //         for(int i =0;i<n;i++){
    //         total+=nums[i];
    //            if(nums[i]<nums[mini]){
    //             mini=i;
    //         }
    //     }    
    //    }
       
        return ans;
    }
};